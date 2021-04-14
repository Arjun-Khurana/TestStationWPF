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
using System.Diagnostics;
using NationalInstruments.Visa;
using Ivi.Visa;

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
            //bool status;
            //byte fwStatus = 0;
            //status = BAWrapper.ConnectV2API("172.16.81.46", ref fwStatus);
            //if (!status)
            //{
            //    Debug.WriteLine("Error Connection");
            //    return;
            //}
            //else
            //{
            //    Debug.WriteLine("Connected");
            //}

            //status = BAWrapper.SetBAConfigAPI(1, 25781250, 0, 1, 2);
            //if (!status)
            //{
            //    Debug.WriteLine("Error SetBAConfigAPI");
            //    return;
            //}
            //else
            //{
            //    Debug.WriteLine("Changed Config");
            //}

            //// Setting TX will set RX Pattern automatically
            //status = BAWrapper.SetPatternAPI(0, 9, 0xFFFF0000, true, 0);
            //if (!status)
            //{
            //    Debug.WriteLine("Error SetPatternAPI");
            //    return;
            //}
            //else
            //{
            //    Debug.WriteLine("Changed Pattern");
            //}
            var rm = new ResourceManager();
            var resourceList = rm.Find("ASRL?*");
            foreach (string s in resourceList)
            {
                Debug.WriteLine(s);
            }
            var arroyo = rm.Open(resourceList.First());
            Debug.WriteLine(arroyo.ResourceName);
        }

        private void BackButton(object sender, RoutedEventArgs e)
        {
            NavigationService.GoBack();
        }

        private void TOSARadioChecked(object sender, RoutedEventArgs e)
        {
            Step1.Text = "(1)    Load TOSA into Eval Board";
        }

        private void ROSARadioChecked(object sender, RoutedEventArgs e)
        {
            Step1.Text = "(1)    Load ROSA into Eval Board";
        }
    }
}
