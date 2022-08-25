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
    /// info.xaml 的交互逻辑
    /// </summary>
    public partial class info : Window
    {
        public info()
        {
            InitializeComponent();
            info1.Text = "IPv4地址:" + MainWindow.connect.IPv4;
            info2.Text = "端口:" + MainWindow.connect.prot;
        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
