using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace little_game.client.wpf
{
    internal class Files
    {
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(string lpAppName, string lpKeyName, string lpDefault, StringBuilder lpReturnedString, int nSize, string lpFileName);
        [DllImport("kernel32")]
        public static extern int WritePrivateProfileString(string lpApplicationName, string lpKeyName, string lpString, string lpFileName);
        [DllImport("kernel32")]
        static extern int GetPrivateProfileInt(string lpAppName, string lpKeyName,int nDefault, 
            string lpFileName//绝对路径
            );
        public static int ReadIni(string section, string key, int def, 
            string filePath//绝对路径
            )
        {
            return GetPrivateProfileInt(section, key, def, filePath);
        }
        public static string ReadIni(string section, string key, string def,
            string filePath//绝对路径
            )
        {

            StringBuilder read = new StringBuilder(1024);
            GetPrivateProfileString(section, key, def, read, 2147483647, filePath);
            return read.ToString();
        }
        public static int Writeini(string section, string key, string value,
            string filePath//绝对路径
            )
        {
            if (!File.Exists(filePath)) return -1;
            else return WritePrivateProfileString(section, key, value, filePath);
        }
        public static void Create(string file, int mode)
        {
            switch (mode)
            {
                case 0:
                    string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, file);
                    FileStream fs = File.Create(path);
                    fs.Close();
                    break;
                case 1:
                    FileStream f1 = File.Create(file);
                    f1.Close();
                    break;
                case 2:
                    string pathf = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, file);
                    Directory.CreateDirectory(pathf);
                    break;
                case 3:
                    Directory.CreateDirectory(file);
                    break;
                default:
                    return;
            }
        }
    }
}
