using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace little_game.client.wpf
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private byte[] buffer = new byte[1024 * 1024 * 2];
        private static Socket Socket;
        private int len;
        public MainWindow()
        {
            Startconnect();
            Thread thread = new Thread(Getip);
            thread.IsBackground = true;
            thread.Start();
            InitializeComponent();
            Thread.Sleep(1000);
        }
        private void Getip()
        {
            try
            {
                Socket.Send(Encoding.UTF8.GetBytes("1"));
                len = Socket.Receive(buffer);
                string a = Encoding.UTF8.GetString(buffer, 0, len);
                int b;
                if (!int.TryParse(a, out b)) throw new FormatException();
                connect.playercode = b;
                b = 0;
                len = Socket.Receive(buffer);
                a = Encoding.UTF8.GetString(buffer, 0, len);
                if (!int.TryParse(a, out b)) throw new FormatException();
                connect.protplay = b;
                a = String.Empty;
                len = 0;
                len = Socket.Receive(buffer);
                a = Encoding.UTF8.GetString(buffer, 0, len);
                if (a != "3") throw new Exceptions("服务端已经关闭", 32765);
                a = String.Empty;
                len = 0;
            }
            catch (FormatException e)
            {
                MessageBox.Show("错误：FormatException\n在"+e.StackTrace," 错误",MessageBoxButton.OK, MessageBoxImage.Error);
                Environment.Exit(-2);
            }
            catch (SocketException e)
            {
                string msg0;
                switch (e.ErrorCode)
                {
                    case 10048:
                        msg0 = "地址正在使用中";
                        break;
                    case 10050:
                        msg0 = "网络子系统出现故障";
                        break;
                    case 10053:
                        msg0 = "无法连接到服务器";
                        break;
                    case 10054:
                        msg0 = "连接被远程端重置";
                        break;
                    case 10060:
                        msg0 = "连接超时";
                        break;
                    case 10049:
                        msg0 = "本地计算机的地址不可用";
                            break;
                        default:
                        msg0 = "其他错误";
                        break;
                }
                MessageBox.Show("错误:SocketException\nerrorcode:" + e.ErrorCode+"\n"+msg0, "错误", MessageBoxButton.OK, MessageBoxImage.Error);
                Environment.Exit(e.ErrorCode);
            }
            catch (Exceptions e)
            {
                if(e.ErrerCode==32765) MessageBox.Show(e.Message, "提示",MessageBoxButton.OK,MessageBoxImage.Information);
               else MessageBox.Show(e.Message+"\n抛出错误位置:\n"+e.StackTrace, "提示");
                Environment.Exit(e.ErrerCode);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                Environment.Exit(GetHashCode());
            }
        }
        private void Startconnect()
        {
            try
            {
                Socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                IPAddress address = IPAddress.Parse(connect.IPv4);
                IPEndPoint endPoint = new IPEndPoint(address, connect.prot);
                Socket.Connect(endPoint);
                
            }
            catch (FormatException)
            {
                MessageBox.Show("错误：FormatException", " 错误", MessageBoxButton.OK, MessageBoxImage.Error);
                Environment.Exit(-2);
            }
            catch (SocketException e)
            {
                MessageBox.Show("错误:SocketException\nerrorcode:" + e.ErrorCode, "错误", MessageBoxButton.OK, MessageBoxImage.Error);
                Environment.Exit(e.ErrorCode);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                Environment.Exit(GetHashCode());
            }
        }

        private void About_Click(object sender, RoutedEventArgs e)
        {
            About about = new About();
            about.ShowDialog();
        }

        private void server_Click(object sender, RoutedEventArgs e)
        {
            info info = new info();
            info.ShowDialog();
        }
        private void Exit_btn_Click(object sender, RoutedEventArgs e)
        {
            Environment.Exit(0);
        }
        public class connect
        {
            public static int prot;
            public static string IPv4;
            public static int protplay;
            public static int playercode;
        }
    }
    public class Exceptions : ApplicationException //应用异常
    {
        public Exceptions(string msg, int errercode)
        {
            message = msg;
            code = errercode;
        }
        int code;
        string message;
        public int ErrerCode
        {
            get
            {
                return code;
            }
        }
        public override string Message
        {
            get
            {
                return message;
            }
        }
    }
}
