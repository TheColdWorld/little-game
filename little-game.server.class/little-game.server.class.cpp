#include "pch.h"
#include "little-game.server.class.h"
class player
{
public:
    //构造函数：给游戏提供初始化服务
    player()
    {
        NAME = "player";
        MXHP =  HP = 1000;
        DMG1 = 20;
        DMG2 = 40;
        TOTALCOIN = COINS = MXMP = MP = 200;
        POT2HAS = POT1HAS = 2;
        GAPPLEHAS = 1;
        W31 = W22 = W21 = W12 = W11 = W02 = W01 = C12 = C11 = C10 = C09 = C08 = C07 = C06 = C05 = C04 = C03 = C02 = C01 = POT6 = POT5 = POT4 = POT3 = POT4HAS = POT3HAS = PROT = DMGE = POTIONS = 0;
        A242 = A241 = A23 = A22 = A21 = A17 = A16 = A15 = A142 = A141 = A13 = A12 = A11 = A07 = A06 = A05 = A042 = A041 = A03 = A02 = A01 = W42 = W41 = W32 = 0;
        E7 = E6 = E5 = E42 = E41 = E3 = E2 = E1 = A47 = A46 = A45 = A042 = A041 = A33 = A32 = A31 = A26 = A25 = 0;
    }
    double Gethp() { return HP; }
    double GetMaxhp() { return MXHP; }
    int Getmp() { return MP; }
    int GetMaxmp() { return MXMP; }
    double GetDmg1() { return DMG1; }
    double GetDmg2() { return DMG2; }
    double GetDmgE() { return DMGE; }
    int GetProt() { return PROT; }
    int GetCoins() { return COINS; }
    int GetTotalcoins() { return TOTALCOIN; }
    std::string Getname() { return NAME; }
    int Getpotions()
    {
        if (POTIONS == 0) return 0;
        else return POTIONS * 10000 + POT3 * 1000 + POT4 * 100 + POT5 * 10 + POT6;
    }
    int HavePoiton1() { return POT1HAS; }
    int HavePotion2() { return POT2HAS; }
    int HavePotion3() { return POT3HAS; }
    int HavePotion4() { return POT4HAS; }
    int HaveGapple() { return GAPPLEHAS; }
    long Getw1has()
    {
        return W01 + W02 * 10 + W11 * 100 + W12 * 1000 + W21 * 10000 + W22 * 100000 + W31 * 1000000 + W32 * 10000000 + W41 * 100000000 + W42 * 10000000000;
    }
    long Getc()
    {
        return C01 + C02 * 10 + C03 * 100 + C04 * 1000 + C05 * 10000 + C06 * 100000 + C07 * 1000000 + C08 * 10000000 + C09 * 100000000 + C10 * 1000000000 + C11 * 10000000000 + C12 * 100000000000;
    }
    int Geta0()
    {
        return A01 + A02 * 10 + A03 * 100 + A041 * 1000 + A042 * 10000 + A05 * 100000 + A06 * 1000000 + A07 * 10000000;
    }
    int Geta1()
    {
        return A11 + A12 * 10 + A13 * 100 + A141 * 1000 + A142 * 10000 + A15 * 100000 + A16 * 1000000 + A17 * 10000000;
    }
    int Geta2()
    {
        return A21 + A22 * 10 + A23 * 100 + A241 * 1000 + A242 * 10000 + A25 * 100000 + A26 * 1000000 + A27 * 10000000;
    }
    int Geta3()
    {
        return A31 + A32 * 10 + A33 * 100 + A341 * 1000 + A342 * 10000 + A35 * 100000 + A36 * 1000000 + A37 * 10000000;
    }
    int Geta4()
    {
        return A41 + A42 * 10 + A43 * 100 + A441 * 1000 + A442 * 10000 + A45 * 100000 + A46 * 1000000 + A47 * 10000000;
    }
    void Takedamege(double demage) { HP -= demage; }
    double Getdemage1() { return DMG1 + DMGE; }
    double Getdemage3() { return DMG2 + DMGE; }
    int DOit(int cho, double takedmg, double ipp, int prop)
    {
        ReloadEDMG();
        ReloadProt();
        prop = PROT;
        switch (cho)
        {

        default:
            break;
        }
    }
private:
    //函数部分
    int Getwear()
    {
        return E1 + E2 * 10 + E3 * 100 + E41 * 1000 + E42 * 10000 + E5 * 100000 + E6 * 1000000 + E7 * 10000000;
    }
    void ReloadProt()
    {
        PROT = 0;
        //装备变量[1:Fe,2:Au,3:Fe-Au合金,4:钻石(C),5.Fe-Au-C合金]
        switch (E1)
        {
        case 1:
            PROT += 2;
            break;
        case 2:
            PROT += 1;
            break;
        case 3:
            PROT =+ 3;
            break;
        case 4:
            PROT += 5;
            break;
        case 5:
            PROT += 6;
            break;
        }
        switch (E2)
        {
        case 1:
            PROT += 4;
            break;
        case 2:
            PROT += 2;
            break;
        case 3:
            PROT = +5;
            break;
        case 4:
            PROT += 5;
            break;
        case 5:
            PROT += 10;
            break;
        }
        switch (E3)
        {
        case 1:
            PROT += 3;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT += 4;
            break;
        case 4:
            PROT += 6;
            break;
        case 5:
            PROT += 8;
        }
        switch (E41)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 3;
        }
        switch (E42)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 3;
        }
        switch (E5)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 2;
        }
        switch (E6)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 2;
        }
        if (E7 == 5) PROT++;
    }
    void ReloadEDMG()
    {
        DMGE = 0;
        switch (EW)
        {
        case 10:
            DMGE += 2;
            break;
        case 11:
            DMGE += 3; 
            break;
        case 20:
            DMGE ++;
            break;
        case 21:
            DMGE += 2;
            break;
        case 30:
            DMGE += 3;
            break;
        case 31:
            DMGE += 4;
            break;
        case 40:
                DMGE += 7;
                break;
        case 41:
            DMGE += 8;
            break;
        case 50:
            DMGE += 9;
            break;
        case 51:
            DMGE += 10;
            break;
        }
    }
    int DrinkPot1()
    {
        if (POT1HAS == 0) return -1;
        else
        {
            POT1HAS--;
            HP += 50;
            return 0;
        }
    }
    int DrinkPot2()
    {
        if (POT2HAS == 0) return -1;
        else
        {
            POT2HAS--;
            MP += 50;
            return 0;
        }
    }
    int DrinkPot3()
    {
        if (POT3HAS == 0) return -1;
        if (POT3 != 0)
        {
            POT3HAS--;
            POT3 = 3;
            return 1;
        }
        else
        {
            POT3HAS--;
            POTIONS++;
            POT3 += 3;
            return 0;
        }
    }
    int DrinkPot4()
    {
        if (POT4HAS == 0) return -1;
        if (POT4 != 0)
        {

            POT4HAS--;
            POT4 = 3;
            return 1;
        }
        else
        {
            POT4HAS--;
            POTIONS++;
            POT4 += 3;
            return 0;
        }
    }
    int EatGapple()
    {
        if (GAPPLEHAS == 0) return -1;
        if (POT3 != 0)
        {
            GAPPLEHAS--;
            HP += 25;
            POT3 = 2;
            return 1;
        }
        else
        {
            GAPPLEHAS--;
            POTIONS++;
            HP += 25;
            POT3 += 2;
            return 0;
        }

    }
    //基础部分
    double HP;//血量(对显)
    double MXHP;//最大血量(对显)
    double DMG1;//伤害1
    double DMG2;//伤害2
    double DMGE;//增加的伤害
    int MP;//体力(对显)
    int MXMP;//最大体力(对显)
    int PROT;//护甲(对显)
    int COINS;//目前金币数
    int TOTALCOIN;//获得金币总数(对显)
    std::string NAME;//名字(对显)
    //药水部分
    int POTIONS;//拥有药水效果数量(对显)
    int POT1HAS;//瞬间治疗
    int POT2HAS;//MP瞬间回复
    int POT3HAS;//生命恢复
    int POT4HAS;//MP恢复
    int GAPPLEHAS;//金苹果[回血+生命恢复(2r)]
    int POT3;
    int POT4;
    int POT5;//中毒[每轮掉25血量][不可死亡]
    int POT6;//凋零[每轮掉50血量]
    //材料变量
    int C01;//木棍
    int C02;//铁锭
    int C03;//铁矿石
    int C04;//钻石
    int C05;//金锭
    int C06;//金矿石
    int C07;//大剑注模
    int C08;//剑注模
    int C09;//苹果
    int C10;//皮革
    int C11;//复合合金锭（2铁2金2钻石->3锭）
    int C12;//金铁合金锭（2铁2金->1锭）
    //武器变量[0:铁,1:金,2:金铁合金,3:钻石,4.复合合金]{1:剑,2:大剑}
    int W01;//2
    int W02;//3
    int W11;//1
    int W12;//2
    int W21;//3
    int W22;//4
    int W31;//7
    int W32;//8
    int W41;//9
    int W42;//10
    //护甲变量[0:铁,1:金,2:金铁合金,3:钻石,4.复合合金]{1:头盔,2:胸甲,3:护腿,41:靴子(左),42:靴子(右),5:手套(左),6:手套(右),7:饰品}
    int A01;//2
    int A02;//4
    int A03;//3
    int A041;//1
    int A042;//1
    int A05;//1
    int A06;//1
    int A07;//0
    int A11;//1
    int A12;//2
    int A13;//1
    int A141;//1
    int A142;//1
    int A15;//1
    int A16;//1
    int A17;//0
    int A21;//3
    int A22;//5
    int A23;//4
    int A241;//1
    int A242;//1
    int A25;//1
    int A26;//1
    int A27;//0
    int A31;//5
    int A32;//8
    int A33;//6
    int A341;//2
    int A342;//2
    int A35;//2
    int A36;//2
    int A37;//0
    int A41;//6
    int A42;//10
    int A43;//8
    int A441;//3
    int A442;//3
    int A45;//2
    int A46;//2
    int A47;//1
    //装备变量[1:Fe,2:Au,3:Fe-Au合金,4:钻石(C),5.Fe-Au-C合金]{0:剑,1:大剑}
    int E1;
    int E2;
    int E3;
    int E41;
    int E42;
    int E5;
    int E6;
    int E7;
    int EW;
};
