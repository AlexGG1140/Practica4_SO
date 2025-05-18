//g++ curle_ok.cpp -o curle_ok -lcurl
#include <iostream>
#include <curl/curl.h>
using namespace std;

int main() {
    //cout << ruta_conectar << endl;
    CURL *curl;
    CURLcode result;
    curl = curl_easy_init();

    if (curl) {
        const char* url = "http://10.226.166.234:8080/";


        curl_easy_setopt(curl, CURLOPT_URL, url);

        result = curl_easy_perform(curl); // envía la petición

        if (result != CURLE_OK) {
            cout << "Error: " << curl_easy_strerror(result) << endl;
        }
        else {
            cout << "Conexión exitosa al servidor." << endl;
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}