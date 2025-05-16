#include "httplib.h"

#include <iostream>

using namespace std;

int conexion_servidor() {
    httplib::Client cli("http://192.268.1.130:8080");

    auto res = cli.Get("/get");

    if (res && res->status == 200) {
        cout << "Respuesta del servidor: " << res->body << endl;
    } else {
        cout << "Error al conectar con el servidor" << endl;
    }

    return 0;
}