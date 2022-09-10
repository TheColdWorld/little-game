using System.Windows;

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
            info3.Text = "你是" + MainWindow.connect.playercode +"号玩家";
        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
