using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TestStationWPF.Models;
using System.Data.SQLite;
using Dapper;
using System.IO;

namespace TestStationWPF.Data
{
    public class DeviceRepository : SqLiteBaseRepository, IDeviceRepository
    {
        public DeviceRepository()
        {
            if (!File.Exists(DbFile))
            {
                CreateDatabase();
            }

        }

        private static void CreateDatabase()
        {
            using (var cnn = DataFileConnection())
            {
                cnn.Open();
                cnn.Execute(
                    @"create table ACTOSADevice
                (
                    id                  integer primary key autoincrement,
                    Part_Number         varchar(255) not null,
                    P_Op                double not null,
                    OMA_Target          double not null,
                    OMA_Tol             double not null,
                    Mask_Margin_Min     double not null,
                    Tr_Max              double not null,
                    Tf_Max              double not null,
                    Rj_Max              double not null,
                    Tj_Max              double not null,
                    Eye_Height          double not null,
                    VECP_Max            double not null
                )");
                cnn.Execute(
                    @"create table ACROSADevice
                (
                    id                  integer identity primary key autoincrement,
                    Part_Number         varchar(255) not null,
                    V_TIA               double not null,
                    V_PD                double not null,
                    TransImpedance_Min  double not null,
                    Tj_Max              double not null,
                    NEP_Max             double not null,
                    RSSSI_VPD           double not null
                )");
                cnn.Execute(
                    @"create table ACTOSAOutput
                (
                    id                  integer identity primary key autoincrement,
                    Part_Number         varchar(255) not null,
                    Job_Number          varchar(255) not null,
                    Unit_Number         varchar(255) not null,
                    Operator            varchar(255) not null,
                    Timestamp           datetime not null,
                    Repeat_Number       integer not null,
                    P_OP                double not null,
                    OMA                 double not null,
                    ER                  double not null,
                    Mask_Margin         double not null,
                    Eye_Height          double not null,
                    VECP                double not null,
                    RJ                  double not null,
                    DJ                  double not null,
                    TJ                  double not null,
                    P_OP_Pass           boolean not null,
                    OMA_Pass            boolean not null,
                    Mask_Margin_Pass    boolean not null,
                    Tr_Pass             boolean not null,
                    Tf_Pass             boolean not null,
                    RJ_Pass             boolean not null,
                    TJ_Pass             boolean not null,
                    Eye_Height_Pass     boolean not null,
                    VECP_Pass           boolean not null,
                    Result              boolean not null
                )");
                cnn.Execute(
                    @"create table ACROSAOutput
                (
                    id                  integer identity primary key autoincrement,
                    Part_Number         varchar(255) not null,
                    Job_Number          varchar(255) not null,
                    Unit_Number         varchar(255) not null,
                    Operator            varchar(255) not null,
                    Timestamp           datetime not null,
                    Repeat_Number       integer not null,
                    Optical_OMA         double not null,
                    Optical_Tj          double not null,
                    RX_Eye_Amplitude    double not null,
                    RX_TransImpedance   double not null,
                    NEP                 double not null,
                    TransImpedance_Pass boolean not null,
                    Tj_Pass             boolean not null,
                    NEP_Pass            boolean not null,
                    Result              boolean not null
                )");
            }
        }

        public ACROSADevice GetACROSADevice(int id)
        {
            if (!File.Exists(DbFile)) return null;

            using (var cnn = DataFileConnection())
            {
                cnn.Open();
                ACROSADevice result = cnn.Query<ACROSADevice>(
                    @"select * from ACROSADevice where id = @id", new { id }).FirstOrDefault();
                return result;
            }
        }

        public ACTOSADevice GetACTOSADevice(int id)
        {
            if (!File.Exists(DbFile)) return null;

            using (var cnn = DataFileConnection())
            {
                cnn.Open();
                ACTOSADevice result = cnn.Query<ACTOSADevice>(
                    @"select * from ACTOSADevice where id = @id", new { id }).FirstOrDefault();
                return result;
            }
        }

        public void SaveACROSADevice(ACROSADevice tosa)
        {
            throw new NotImplementedException();
        }

        public void SaveACROSAOutput(ACROSAOutput result)
        {
            throw new NotImplementedException();
        }

        public void SaveACTOSADevice(ACTOSADevice tosa)
        {
            throw new NotImplementedException();
        }

        public void SaveACTOSAOutput(ACTOSAOutput result)
        {
            throw new NotImplementedException();
        }
    }
}
