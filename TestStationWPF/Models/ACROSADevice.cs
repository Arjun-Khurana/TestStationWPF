using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestStationWPF.Models
{
    public class ACROSADevice
    {
        int id { get; set; }
        string Part_Number { get; set; }
        double V_TIA { get; set; }
        double V_PD { get; set; }
        double TransImpedance_Min { get; set; }
        double Tj_Max { get; set; }
        double NEP_Max { get; set; }
        double RSSSI_VPD { get; set; }

    }
}
