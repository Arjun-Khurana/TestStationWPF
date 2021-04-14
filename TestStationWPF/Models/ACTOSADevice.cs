using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestStationWPF.Models
{
    public class ACTOSADevice
    {
        int id { get; set; }
        string Part_Number { get; set; }
        double P_Op { get; set; }
        double OMA_Target { get; set; }
        double OMA_Tol { get; set; }
        double Mask_Margin_Min { get; set; }
        double Tr_Max { get; set; }
        double Tf_Max { get; set; }
        double Rj_Max { get; set; }
        double Tj_Max { get; set; }
        double Eye_Height { get; set; }
        double VECP_Max { get; set; }

    }
}
