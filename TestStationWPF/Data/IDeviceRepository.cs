using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TestStationWPF.Models;

namespace TestStationWPF.Data
{
    public interface IDeviceRepository
    {
        ACTOSADevice GetACTOSADevice(int id);
        ACROSADevice GetACROSADevice(int id);
        void SaveACTOSADevice(ACTOSADevice tosa);
        void SaveACROSADevice(ACROSADevice tosa);
        void SaveACTOSAOutput(ACTOSAOutput result);
        void SaveACROSAOutput(ACROSAOutput result);
    }

    public class SqLiteBaseRepository
    {
        public static string DbFile
        {
            get { return Environment.CurrentDirectory + "\\DataFile.sqlite"; }
        }

        public static SQLiteConnection DataFileConnection()
        {
            return new SQLiteConnection("Data Source=" + DbFile);
        }
    }

}
