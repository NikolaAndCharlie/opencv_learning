#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>



using namespace cv;

  int g_slider_position = 0;
  int g_run = 1, g_dontset = 0;

  VideoCapture g_cap;

  void onTrackBarSldider(int pos, void* )
  {
   //   g_cap.set(CAP_PROP_POS_FRAMES, pos);
      
      if(!g_dontset)
      {
          g_run = 1;
          g_dontset = 0;
      }


  }


int main()
{
   namedWindow("Example4",WINDOW_AUTOSIZE);     
   g_cap.open("E://learning Opencv3//3.4.0//cup.mp4");
   int frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
   int tmpw = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
   int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);

   std::cout << "Video has " << frames << " frames of dimensions("<< tmpw <<","<<tmph<<")."<< std::endl;

   createTrackbar("Position", "Example4", &g_slider_position,frames,onTrackBarSldider);
   
   Mat frame;

   while(1)
   {
      if(g_run !=0 )
      {
          g_cap >> frame;
          if(frame.empty())
          {
             break;
          }
          int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
          g_dontset = 1;
          setTrackbarPos("Position","Example4", current_pos);
          imshow("Example4",frame);
          std::cout << "step, run = " << g_run << std::endl;
          g_run--;
      }

      char c = (char)waitKey(10);

      if(c == 's')
      {
          g_run = 1;
          std::cout<< "Singal step, run = "<< g_run <<std::endl;
      }

      if(c == 'r')
      {
          g_run = -1;
      }

      if(c == 27)
      {
          break;
      }
   }

   return 0;
}