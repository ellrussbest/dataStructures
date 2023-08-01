#include <iostream>

using namespace std;

namespace c_third_lesson
{
    typedef struct _Service
    {
        class Request
        {
        public:
            int32_t a;
            int32_t b;
        };

        class Response
        {
        public:
            int32_t sum;
        };

        Request request;
        Response response;
    } Service;
}

bool add(c_third_lesson::Service::Request &request, c_third_lesson::Service::Response &response)
{
    cout << response.sum << endl;
    response.sum = request.a + request.b;
    cout << response.sum << endl;
    return true;
}

int main()
{

    c_third_lesson::Service service;

    service.request.a = 10;
    service.request.b = 20;

    add(service.request, service.response);
    int x = 10;
    int y = 25;
    int z = x + y;

    cout << "Sum of x+y = " << z;
}