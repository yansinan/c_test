#include <stdio.h>
// 结构体测试
typedef enum {
    PIXFORMAT_RGB565,    // 2BPP/RGB565
    PIXFORMAT_YUV422,    // 2BPP/YUV422
    PIXFORMAT_GRAYSCALE, // 1BPP/GRAYSCALE
    PIXFORMAT_JPEG,      // JPEG/COMPRESSED
    PIXFORMAT_RGB888,    // 3BPP/RGB888
    PIXFORMAT_RAW,       // RAW
    PIXFORMAT_RGB444,    // 3BP2P/RGB444
    PIXFORMAT_RGB555,    // 3BP2P/RGB555
} pixformat_t;

typedef enum {
    FRAMESIZE_96X96,    // 96x96
    FRAMESIZE_QQVGA,    // 160x120
    FRAMESIZE_QCIF,     // 176x144
    FRAMESIZE_HQVGA,    // 240x176
    FRAMESIZE_240X240,  // 240x240
    FRAMESIZE_QVGA,     // 320x240
    FRAMESIZE_CIF,      // 400x296
    FRAMESIZE_HVGA,     // 480x320
    FRAMESIZE_VGA,      // 640x480
    FRAMESIZE_SVGA,     // 800x600
    FRAMESIZE_XGA,      // 1024x768
    FRAMESIZE_HD,       // 1280x720
    FRAMESIZE_SXGA,     // 1280x1024
    FRAMESIZE_UXGA,     // 1600x1200
    // 3MP Sensors
    FRAMESIZE_FHD,      // 1920x1080
    FRAMESIZE_P_HD,     //  720x1280
    FRAMESIZE_P_3MP,    //  864x1536
    FRAMESIZE_QXGA,     // 2048x1536
    // 5MP Sensors
    FRAMESIZE_QHD,      // 2560x1440
    FRAMESIZE_WQXGA,    // 2560x1600
    FRAMESIZE_P_FHD,    // 1080x1920
    FRAMESIZE_QSXGA,    // 2560x1920
    FRAMESIZE_INVALID
} framesize_t;
typedef struct
{
    int xclk_freq_hz;               /*!< Frequency of XCLK signal, in Hz. EXPERIMENTAL: Set to 16MHz on ESP32-S2 or ESP32-S3 to enable EDMA mode */

    pixformat_t pixel_format;       /*!< Format of the pixel data: PIXFORMAT_ + YUV422|GRAYSCALE|RGB565|JPEG  */
    framesize_t frame_size;         /*!< Size of the output image: FRAMESIZE_ + QVGA|CIF|VGA|SVGA|XGA|SXGA|UXGA  */
} camera_config_t;
static camera_config_t camera_config = 
{
	//XCLK 20MHz or 10MHz for OV2640 double FPS (Experimental)
	.xclk_freq_hz = 10000000,


	.pixel_format = PIXFORMAT_JPEG,//YUV422,GRAYSCALE,RGB565,JPEG
	.frame_size = FRAMESIZE_UXGA,//QQVGA-UXGA Do not use sizes above QVGA when not JPEG
	// .pixel_format = PIXFORMAT_GRAYSCALE,//YUV422,GRAYSCALE,RGB565,JPEG
	// .frame_size = FRAMESIZE_QQVGA,//QQVGA-UXGA Do not use sizes above QVGA when not JPEG
};
// 根据指针数组，求数组长度
int fun(char **a){
    printf("===>sizeof(*a)/sizeof(**a) %d \n",sizeof(*a)/sizeof(**a));
}
// 函数内声明变量的传出
int fun2(char **a){
    printf("a[0]before %s \n",a[0]);//22
    char *tmp="4444";
    a[0]=tmp;//数组中第一个指针的值变成新地址;
    printf("----------a[0]after (a[0]) %s \n",(char *)(a[0]));//输出数组第一个指针指向的数据,4444 

    // printf("before \n");//输出数组第一个指针指向的数据,4444
    // char *tmp2="55555";
    // printf("after %p \n",*tmp2);
    // printf("after %s \n",tmp);
    // // 数组首地址是常量，不能改，测试idx=1
    // *(a[1])[0]='b';//数组中第一个指针的指向区域，变成新数据;
    // printf("a[1]after *(a[1]) %s \n",a[1]);//输出数组第一个指针指向的数据
}
int main()
{
    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");
    char *a[100];
    fun(a);
    printf("sizeof(a) %d \n",sizeof(a));
    printf("sizeof(*a) %d \n",sizeof(*a));
    printf("sizeof(a)/sizeof(*a) %d \n",sizeof(a)/sizeof(*a));

    // a[0]="22";
    a[1]="333";
    printf("sizeof(a) %d \n",sizeof(a));
    printf("sizeof(*a) %d \n",sizeof(*a));
    printf("sizeof(a)/sizeof(*a) %d \n--------------------------\n",sizeof(a)/sizeof(*a));

    fun2(a);
    printf("-----out-----a[0]after (a[0]) %s \n",(char *)(a[0]));//输出数组第一个指针指向的数据,4444 

    printf("struct %d \n",camera_config.xclk_freq_hz);
    printf("struct %d \n",camera_config.pixel_format);
    printf("struct %d \n",camera_config.frame_size);

    camera_config.xclk_freq_hz=10000;
    camera_config.pixel_format=1;
    camera_config.frame_size=2;

    printf("struct %d \n",camera_config.xclk_freq_hz);
    printf("struct %d \n",camera_config.pixel_format);
    printf("struct %d \n",camera_config.frame_size);

    int in_w=320,in_h=260;
    int mem_need=in_w*in_h > 320*240 ? 80*1024 : 30*1024;
    printf("mem_need %d \n",mem_need);
    in_w=160,in_h=120;
    mem_need=in_w*in_h > 320*240 ? 80*1024 : 30*1024;
    printf("mem_need %d \n",mem_need);
    return 0;
}