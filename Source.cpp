/*----------------------------------------------------------------------LIBRERIAS------------------------------------------------------------------------------*/

#include <iostream>

#include <opencv2/core.hpp>      
#include <opencv2/imgcodecs.hpp>	
#include <opencv2/highgui.hpp>   
#include <opencv2/imgproc.hpp>	


// Definicion de espacios
using namespace std;
using namespace cv;
/*----------------------------------------------------------------------FUNCIONES------------------------------------------------------------------------------*/



/*----------------------------------------------------------------------PROGRAMA PRINCIPAL------------------------------------------------------------------------------*/

int main()
{

	Mat img = imread("escena.bmp", 1);
	if (img.empty())
		return -1;



	/*------------------------------------------------------------------------IMPRIMIR VALORES DE LOS PIXELES ------------------------------------------------*/
	Vec3b pix_bgr;
	pix_bgr = img.at<Vec3b>(50, 80);
	cout << "Pixel 50 y 80 en color: " << pix_bgr << endl;
	pix_bgr = img.at<Vec3b>(135, 30);
	cout << "Pixel 135,30 en color: " << pix_bgr << endl;
	pix_bgr = img.at<Vec3b>(256, 256);
	cout << "Pixel 256,256 en color: " << pix_bgr << endl;
	pix_bgr = img.at<Vec3b>(450, 500);
	cout << "Pixel 450, 500 en color: " << pix_bgr << endl;

	/*----------------------------------------------------------------------------------BILLLO----------------------------------------------------------------*/
	//AZUL
	float suma = 0;
	Vec3b pixel = 0;
	for (int a = 0; a <= (img.rows - 1); a++)
	{
		for (int b = 0; b <= (img.cols - 1); b++)
		{
			pixel = img.at<Vec3b>(a, b);
			suma = suma + pixel[0];
		}
	}
	int brillo_Blue = suma / (img.rows * img.cols);

	cout << "El valor del brillo canal azul es : " << brillo_Blue << endl;

	//VERDE
	suma = 0;
	for (int a = 0; a <= (img.rows - 1); a++)
	{
		for (int b = 0; b <= (img.cols - 1); b++)
		{
			pixel = img.at<Vec3b>(a, b);
			suma = suma + pixel[1];
		}
	}
	int brillo_Green = suma / (img.rows * img.cols);

	cout << "El valor del brillo canal verde es : " << brillo_Green << endl;


	//ROJO
	suma = 0;
	for (int a = 0; a <= (img.rows - 1); a++)
	{
		for (int b = 0; b <= (img.cols - 1); b++)
		{
			pixel = img.at<Vec3b>(a, b);
			suma = suma + pixel[2];
		}
	}
	int brillo_Red = suma / (img.rows * img.cols);

	cout << "El valor del brillo canal rojo es : " << brillo_Red << endl;






	/*----------------------------------------------------------------------------------CONTRASTE----------------------------------------------------------------*/

	//AZUL
	suma = 0;
	for (int a = 0; a <= (img.rows - 1); a++)
	{
		for (int b = 0; b <= (img.cols - 1); b++)
		{
			pixel = img.at<Vec3b>(a, b);
			suma = suma + pow((pixel[0] - brillo_Blue), 2);
		}
	}

	int contraste_Blue = suma / (img.rows * img.cols);
	contraste_Blue = sqrt(contraste_Blue);
	cout << "El valor del contraste canal azul  es : " << contraste_Blue << endl;

	//VERDE
	suma = 0;
	for (int a = 0; a <= (img.rows - 1); a++)
	{
		for (int b = 0; b <= (img.cols - 1); b++)
		{
			pixel = img.at<Vec3b>(a, b);
			suma = suma + pow((pixel[1] - brillo_Green), 2);
		}
	}

	int contraste_Green = suma / (img.rows * img.cols);
	contraste_Green = sqrt(contraste_Green);
	cout << "El valor del contraste canal verde  es : " << contraste_Green << endl;


	//ROJO
	suma = 0;
	for (int a = 0; a <= (img.rows - 1); a++)
	{
		for (int b = 0; b <= (img.cols - 1); b++)
		{
			pixel = img.at<Vec3b>(a, b);
			suma = suma + pow((pixel[0] - brillo_Red), 2);
		}
	}

	int contraste_Red = suma / (img.rows * img.cols);
	contraste_Red = sqrt(contraste_Red);
	cout << "El valor del contraste canal rojo  es : " << contraste_Red << endl;




	/*----------------------------------------------------------------------MUESTRA IMAGEN------------------------------------------------------------------------------*/

	namedWindow("ESCENA", WINDOW_NORMAL);
	imshow("ESCENA", img);





	waitKey(0);

	return 0;
}