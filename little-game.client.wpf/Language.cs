using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Markup;

namespace little_game.client.wpf
{
    internal class Language
    {
        public static void Init()
        {
            if (!Directory.Exists(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "lang"))) throw new FatalExceptions("错误:未找到语言文件\n请从最新构建按中获取\nError: Language file not found\nPlease get it from the latest build press\n", "错误", -1);
            else
            {
                string langinifile = Path.Combine(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "lang")  ,Settings.Language);
                startertitle = Files.ReadIni("Lang_Window", "startertitle", null,langinifile );
                maintitle1 = Files.ReadIni("Lang_Window", "maintitle1", null, langinifile);
                maintitle2 = Files.ReadIni("Lang_Window", "maintitle2", null, langinifile);
                info1start = Files.ReadIni("Lang_Window", "info1start", null, langinifile);
                info2start = Files.ReadIni("Lang_Window", "info2start", null, langinifile);
                info3start = Files.ReadIni("Lang_Window", "info3start", null, langinifile);
                info3end = Files.ReadIni("Lang_Window", "info3end", null, langinifile);
                mainwindowtocheck=Files.ReadIni("Lang_Window", "mainwindowtocheck", null, langinifile);
                mainwindowabout = Files.ReadIni("Lang_Window", "mainwindowabout", null, langinifile);
            }
        }
       static string startertitle;
        static string maintitle1;
        static string maintitle2;
        static string info1start;
        static string info2start;
        static string info3start;
        static string info3end;
        static string mainwindowtocheck;
        static string mainwindowabout;
        public static string Startertitle
        {
            get { return startertitle; }
        }
        public static string Maintitle1
        {
            get { return maintitle1; }
        }
        public static string Maintitle2
        {
            get { return maintitle2; }
        }
        public static string Info1start
        {
            get { return info1start; }
        }
        public static string Info2start
        {
            get { return info2start; }
        }
        public static string Info3start
        {
            get { return info3start; }
        }
        public static string Info3end
        {
            get { return info3end; }
        }
        public static string Mainwindowtocheck
        {
            get { return mainwindowtocheck; }
        }
        public static string Mainwindowabout
        {
            get { return mainwindowabout; }
        }

    }
    class Settings
    {
        public static void Init(string Language, bool Backgroundenable, int Bavkgroundmode, string Backgroundimage,string BackgroundOpacity)
        {
            language = Language;
            backgroundenable = Backgroundenable;
            bavkgroundmode = Bavkgroundmode;
            backgroundimage = Backgroundimage;
            backgroundOpacity= Convert.ToDouble(BackgroundOpacity);
        }
        static string language;
        static bool backgroundenable;
        static int bavkgroundmode;
        static string backgroundimage;
        static double backgroundOpacity;
        static public string Language
        {
            get { return language; }
        }
        static public bool Backgroundenable
        {
            get { return backgroundenable; }
        }
        static public int Bavkgroundmode
        {
            get { return bavkgroundmode; }
        }
        static public string Backgroundimage
        {
            get { return backgroundimage; }
        }
       public static double BackgroundOpacity
        {
            get { return backgroundOpacity; }
        }
    }
}
