#include <opencv2/core/core.hpp> 
#include <opencv2/opencv.hpp>   
#include <opencv2/highgui/highgui.hpp>    
#include <iostream>
#include <chrono>
using namespace cv;  
using namespace std;

string ltos(long l)  
{  
    ostringstream os;  
    os<<l;  
    string result;  
    istringstream is(os.str());  
    is>>result;  
    return result;  
     
}  
bool getDistortMap(Size imageSize, Mat& map1, Mat& map2)
{
    cv::Mat cameraMatrix(3,3,CV_64F);
    cv::Mat distCoeffs(5,1,CV_64F);
    cameraMatrix.at<double>(0,0)=1504.8543663376870;
    /*assign cameraMaxtrix*/
    cameraMatrix.at<double>(0,1)=0;
    cameraMatrix.at<double>(0,2)=659.78622895675744;
    cameraMatrix.at<double>(1,0)=0;
    cameraMatrix.at<double>(1,1)=1504.8543663376870;
    cameraMatrix.at<double>(1,2)=328.01100462215209;
    cameraMatrix.at<double>(2,0)=0;
    cameraMatrix.at<double>(2,1)=0;
    cameraMatrix.at<double>(2,2)=1.0;

    distCoeffs.at<double>(0,0)=-0.40493671554831040;
    distCoeffs.at<double>(1,0)=0.21944525778408466;
    distCoeffs.at<double>(2,0)=0.0073780906241826235;
    distCoeffs.at<double>(3,0)=-0.0033246719821387345;
    distCoeffs.at<double>(4,0)=0.17782514768790580;
    cout << cameraMatrix<<endl;
    cout << distCoeffs<<endl;
    //read camera instrisic
    if(imageSize.width - 0 < 0.00001 || imageSize.height - 0 < 0.00001)
         return false;
    initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(),
                            getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
                            imageSize, CV_16SC2, map1, map2);
    return true;
} 
std::time_t getTimeStamp()  
{  
        std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());  
        auto tmp=std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());  
        std::time_t timestamp = tmp.count();  
        //std::time_t timestamp = std::chrono::system_clock::to_time_t(tp);  
        return timestamp;  
}

const char* usage =
"\n./myreadVideoToPng input file\n"
"\n./myreadVideoToPng -i=../data/test.avi [-o=../data] [-n=3]"
"\n"; 
static void help()
{
	cout << usage;
}

int main(int argc,char** argv)  
{
    cv::CommandLineParser parser(argc, argv, "{help||}{i|../input/test.avi| input file}{o|../output/|output image path}{n|3|}");
    if(argc<2)
    {
        help();
        return 0;
    }
    std::string videoName = parser.get<string>("i");
    std::string outputPath = parser.get<string>("o");
    int n = parser.get<int>("n");
    VideoCapture capture(videoName);//如果是笔记本，0打开的是自带的摄像头，1 打开外接的相机  
    int isColor=1;

    double fps = capture.get(CV_CAP_PROP_FPS); 
    //VideoWriter writer("VideoTest.avi", CV_FOURCC('X','V','I','D'), rate, videoSize,isColor);  
    cv::Mat frame, showFrame;  
    long count=0;
    while (capture.read(frame))  
    {
        showFrame = frame.clone();
        imshow("video", showFrame);
        string fname = outputPath + "Img" + ltos(count) + ".png";
	if(0==(count%n))
	{
        imwrite(fname,frame);
        cout << "Save " << fname << endl;
	}
        count++;
    }
    return 0;  
}
