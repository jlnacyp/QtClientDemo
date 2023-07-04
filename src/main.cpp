/*
 * Copyright(C) 2010,Hikvision Digital Technology Co., Ltd
 *
 * ????????main.cpp
 * ??    ????
 * ????·Ú??1.0
 * ??    ?????????
 * ?????????2009??11??12??
 * ???????
 */

#include "qtclientdemo.h"
#include <QTextCodec>
#include <QtGui>
#include <QApplication>


//??????
QtClientDemo* gqtclinetdemo;

/*******************************************************************
      Function:   main
   Description:   ??????????
     Parameter:   (IN)   int argc
                  (IN)   char *argv[]
        Return:   0--?????-1--????
**********************************************************************/
int main(int argc, char *argv[])
{
    gqtclinetdemo = NULL;
    QApplication a(argc, argv);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

    //Add translation file.
    QTranslator translator;
    BOOL bSuc;
    bSuc = translator.load("..//..//..//..//translation//QtDemo_zh_CN");
    if (!bSuc)
    {
         bSuc = translator.load("..//..//translation//QtDemo_zh_CN");
    }
    if (!bSuc)
    {
        translator.load("translation/QtDemo_zh_CN");
    }
    if (!bSuc)
    {
        translator.load("./QtDemo_zh_CN");
    }
    a.installTranslator(&translator);

    //Show the main window.
    QtClientDemo w;
    w.show();
    gqtclinetdemo =&w;
    return a.exec();
}
