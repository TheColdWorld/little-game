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
using System.Windows.Shapes;

namespace little_game.client.wpf
{
    /// <summary>
    /// starter.xaml 的交互逻辑
    /// </summary> 

    public partial class starter : Window
    {
        bool closed = true;
        public starter()
        {
            InitializeComponent();
        }
        protected override void OnClosed(EventArgs e)
        {
            if (closed) Environment.Exit(0);
            else base.OnClosed(e);
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrEmpty(IPv4.Text) || string.IsNullOrWhiteSpace(IPv4.Text))
            {
                MessageBox.Show("错误：IPv4地址未填写,请输入", "错误");
                return;
            }
            else MainWindow.connect.IPv4 = IPv4.Text;
            if (string.IsNullOrEmpty(port.Text) || string.IsNullOrWhiteSpace(port.Text))
            {
                MessageBox.Show("错误：端口未填写,请输入", "错误");
                return;
            }
            if (!int.TryParse(port.Text, out MainWindow.connect.prot))
            {
                MessageBox.Show("错误：端口填写违法，请重新填写", "错误");
                return;
            }
            if (MainWindow.connect.prot > 65535)
            {
                MessageBox.Show("端口大于端口上线值，请重新输入", "错误");
                return;
            }
            else
            {
                if (MainWindow.connect.prot <= 1024)
                {
                    if (MessageBox.Show("当前端口小于等于1024，既有可能被占用，是否继续？", "警告", MessageBoxButton.YesNo, MessageBoxImage.Warning) == MessageBoxResult.No) return;
                }
                MainWindow mainWindow = new MainWindow();
                closed = false;
                Close();
                mainWindow.Show();
            }
        }
        
    }
}
