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

namespace TestStationWPF
{
    /// <summary>
    /// Interaction logic for ACTestHome.xaml
    /// </summary>
    public partial class ACTestHome : Page
    {
        public ACTestHome()
        {
            InitializeComponent();
        }

        private void StartTestButton(object sender, RoutedEventArgs e)
        {

        }

        private void BackButton(object sender, RoutedEventArgs e)
        {
            NavigationService.GoBack();
        }
    }
}
