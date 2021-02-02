
#include <opencv2/opencv.hpp>
#include <definition.h>
#include <toyoloconvert.h>
#include <trainvalspilit.h>
int main(int argc,char* argv[])
{
    int counter;
    string labelDir;
    string imgsDir;
    string labelMap;
    std::vector<string> labelsAddr;

    printf("Program Name Is: %s",argv[0]);
    cout<<"\nOpenCV Version:"<<CV_VERSION<<endl;
    if(argc==1)
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name\n");
        printf("USAGE:\n");
        printf("\tObj2YOLO labelDir imgsDir labelMap newImageDir labelsAddrs\n");
        printf("\ttoYOLO labelDir imgsDir labelMap labelsAddrs\n");
        printf("\ttrainval rawImgDir rawLabelDir DataSpilitedDir Percent\n");

    if(argc>=2)
    {
        printf("\nNumber Of Arguments Passed: %d",argc);
        if(strcmp(argv[1],"toYOLO")==0){
            cout<<"\nTo Yolo Convert selected:\n";
            labelDir=argv[2];
            imgsDir=argv[3];
            labelMap=argv[4];
            for(counter=5;counter<argc;counter++)
                labelsAddr.push_back(argv[counter]);
            toyoloconvert* yoloConvert=new toyoloconvert();
            yoloConvert->setConfig(labelDir,imgsDir,labelMap,labelsAddr);
            yoloConvert->convert();
        }
        if(strcmp(argv[1],"Obj2YOLO")==0){
            cout<<"\nObject EXtraction to YOLO Convert selected:\n";
            labelDir=argv[2];
            imgsDir=argv[3];
            labelMap=argv[4];
            toyoloconvert* yoloConvert=new toyoloconvert();
            if(strcmp(argv[6],"rect")==0){
                yoloConvert->rect=true;
                for(counter=7;counter<argc;counter++)
                    labelsAddr.push_back(argv[counter]);
            }
            else if(argv[6]=="withaug"){
                yoloConvert->augment=true;
                for(counter=7;counter<argc;counter++)
                    labelsAddr.push_back(argv[counter]);
            }
            else{
            for(counter=6;counter<argc;counter++)
                labelsAddr.push_back(argv[counter]);
            }
            yoloConvert->setConfig(labelDir,imgsDir,labelMap,labelsAddr);
            yoloConvert->convertObjs(argv[5]);
        }
        if(strcmp(argv[1],"trainval")==0){
            cout<<"\nTrain-Val Spiliting selected:\n";
            string rawImgDir=argv[2];
            string rawLabelDir=argv[3];
            string DataSpilitedDir=argv[4];
            string Percent=argv[5];
            trainvalspilit* spiliter=new trainvalspilit();
            spiliter->init(rawImgDir,rawLabelDir,DataSpilitedDir,Percent);
            spiliter->spilit();
        }
    }

    return 0;
}
