#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include <zmq.hpp>
#include <zmq_addon.hpp>

using namespace std::chrono_literals;

int main() {

  // initialize the zmq context with a single IO thread
  zmq::context_t context{1};
  zmq::message_t data(1 << 26);

  // construct a REP (reply) socket and bind to interface
  zmq::socket_t socket{context, zmq::socket_type::pair};
  socket.bind("ipc://socket.ipc");

  // prepare some static data for responses

  for (;;) {
    auto start = std::chrono::high_resolution_clock::now();

    zmq::message_t request;

    // receive a request from client
    socket.recv(request, zmq::recv_flags::none);
    // std::cout << "Received message of size: " << request.size() << std::endl;

    // simulate work
    // std::this_thread::sleep_for(1s);

    // send the reply to the client
    socket.send(data, zmq::send_flags::none);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Duration: " << duration.count() << "ms" << std::endl;

    std::this_thread::sleep_for(1s);
  }

  return 0;
}
