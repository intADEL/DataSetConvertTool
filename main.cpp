
#include <opencv2/opencv.hpp>
#include <definition.h>
#include <toyoloconvert.h>
#include <trainvalspilit.h>
#include <ocrdataconvert.h>
#include <platecrop.h>
int main(int argc,char* argv[])
{
    int counter;
    string labelDir;
    string imgsDir;
    string labelMap;
    string labelFile;
    std::vector<string> labelsAddr;

    printf("Program Name Is: %s",argv[0]);
    cout<<"\nOpenCV Version:"<<CV_VERSION<<endl;
    if(argc==1)
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name\n");
        printf("USAGE:\n");
        printf("\tObj2YOLO labelDir imgsDir labelMap newImageDir labelsAddrs\n");
        printf("\ttoYOLO labelDir imgsDir labelMap labelsAddrs\n");
        printf("\ttrainval rawImgDir rawLabelDir DataSpilitedDir Percent\n");
        printf("\tFilename2OCR ImgDir LabelDir methodnum");

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
        if(strcmp(argv[1],"Filename2OCR")==0){
            cout<<"\nFilename2OCR selected:\n";
            string ImgDir=argv[2];
            string LabelDirName=argv[3];
            string MethodNum=argv[4];
            OCRDataConvert* ocr=new OCRDataConvert();
            ocr->init(ImgDir,LabelDirName,stoi(MethodNum));
            ocr->run();

        }
        if(strcmp(argv[1],"platecrop")==0){
            cout<<"\nFPlate Crop selected:\n";
            labelFile=argv[2];         
            imgsDir=argv[3];
            labelDir=argv[4];
            string cropDir=argv[5];
            labelMap=argv[6];
            int method=stoi(argv[7]);
            platecrop* pcrop=new platecrop();
            pcrop->init(labelFile,imgsDir,labelDir,cropDir,labelMap,method);
            pcrop->run();
        }
    }

    return 0;
}
