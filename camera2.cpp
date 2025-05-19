//g++ camera2.cpp -o camera2 -lcurl `pkg-config --cflags --libs opencv4`
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <opencv2/opencv.hpp>

using namespace std;

// Función para guardar la imagen descargada en un archivo
size_t write_data(void *ptr, size_t size, size_t nmemb, void *userdata) {
    FILE *fp = (FILE *)userdata;
    return fwrite(ptr, size, nmemb, fp);
}

int main() {
    while (true) {
        CURL *curl = curl_easy_init();
        if (curl) {
            FILE *fp = fopen("camera2.jpg", "wb");
            curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.1.130:8080/camera2");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

            CURLcode res = curl_easy_perform(curl);
            fclose(fp);
            curl_easy_cleanup(curl);

            if (res != CURLE_OK) {
                cout << "Error: " << curl_easy_strerror(res) << endl;
                continue;
            }

            // Mostrar imagen con OpenCV
            cv::Mat img = cv::imread("camera2.jpg");
            if (img.empty()) {
                cout << "No se pudo cargar la imagen." << endl;
                continue;
            }

            cv::imshow("Imagen desde servidor (pulsa q para salir)", img);
            if (cv::waitKey(50) == 'q') {
                break;
            }
        }
    }

    cv::destroyAllWindows();
    return 0;
}