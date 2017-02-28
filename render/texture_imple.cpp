#include "renderluo.h"

char* gltloadbmp(const char *szfilename,int &iwidth,int &iheight)  
{  
    //���ļ�   
    FILE *pfile=fopen(szfilename,"rb");  
    if(pfile==0)  
    {  
        exit(0);  
    }  
    //��ȡͼ���С bmpͼ���߷���ǰ�����ֽڣ�   
    fseek(pfile,0x0012,SEEK_SET);//pfileָ��ƫ��0x0012λ�����ɹ���ָ��SEEK_SET���ļ���ͷ   
    fread(iwidth,sizeof(iwidth),1,pfile);//����1��Ԫ�أ�ÿ��Ԫ��sizeof(iwidth)���ֽڣ�iwidth���ڽ������ݵ��ڴ��ַ   
    fread(iheight,sizeof(iheight),1,pfile);   
    //�������س���  
    int pixellength=iwidth*3;//3:BGR��blue��green��red��   
    while(pixellength%4!=0)//��ȡ��ʱ���ǰ�int��ȡ�ģ�Ҳ����4�ֽ�   
    {  
        pixellength++;  
    }  
    pixellength=pixellength*(iheight);  
    //��ȡ��������  
    char *pixeldata=(char*)malloc(pixellength);  
    if(pixeldata==0)  
    {  
        exit(0);  
    }   
    fseek(pfile,54,SEEK_SET);  
    fread(pixeldata,pixellength,1,pfile);  
    //�ر��ļ�  
    fclose(pfile);
	
    return pixeldata;  
}  