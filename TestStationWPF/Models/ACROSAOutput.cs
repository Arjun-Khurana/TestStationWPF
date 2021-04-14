using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestStationWPF.Models
{
    public class ACROSAOutput
    {
        int id { get; set; }
        string Part_Number { get; set; }
        string Job_Number { get; set; }
        string Unit_Number { get; set; }
        string Operator { get; set; }
        DateTime Timestamp { get; set; }
        int Repeat_Number { get; set; }
        double Optical_OMA { get; set; }
        double Optical_Tj { get; set; }
        double RX_Eye_Amplitude { get; set; }
        double RX_TransImpedance { get; set; }
        double NEP { get; set; }
        bool TransImpedance_Pass { get; set; }
        bool Tj_Pass { get; set; }
        bool NEP_Pass { get; set; }
        bool Result { get; set; }
    }
}
