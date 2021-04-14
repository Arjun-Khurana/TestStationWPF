using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestStationWPF.Models
{
    public class ACTOSAOutput
    {
        int id { get; set; }
        string Part_Number { get; set; }
        string Job_Number { get; set; }
        string Unit_Number { get; set; }
        string Operator { get; set; }
        DateTime Timestamp { get; set; }
        int Repeat_Number { get; set; }
        double P_OP { get; set; }
        double OMA { get; set; }
        double ER { get; set; }
        double Mask_Margin { get; set; }
        double Eye_Height { get; set; }
        double VECP { get; set; }
        double RJ { get; set; }
        double DJ { get; set; }
        double TJ { get; set; }
        bool P_OP_Pass { get; set; }
        bool OMA_Pass { get; set; }
        bool Mask_Margin_Pass { get; set; }
        bool Tr_Pass { get; set; }
        bool Tf_Pass { get; set; }
        bool RJ_Pass { get; set; }
        bool TJ_Pass { get; set; }
        bool Eye_Height_Pass { get; set; }
        bool VECP_Pass { get; set; }
        bool Result { get; set; }
    }
}
