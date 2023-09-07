#include <iostream>
#include <string>
#include <chrono>
#include <thread>


#include <zmq.hpp>
#include <zmq_addon.hpp>



using namespace std::chrono_literals;

int main() {
  // initialize the zmq context with a single IO thread
  zmq::context_t context{1};

  // construct a REQ (request) socket and connect to interface
  zmq::socket_t socket{context, zmq::socket_type::pair};
  socket.connect("ipc://socket.ipc");

  // set up some static data to send
  const std::vector<uint8_t> data(1 << 26);

  for (;;) {
    // send the request message
    // std::cout << "Sending message of size: " << data.size() << std::endl;
    socket.send(zmq::buffer(data), zmq::send_flags::none);
    std::this_thread::sleep_for(1s);

    // wait for reply from server
    zmq::message_t reply{};
    socket.recv(reply, zmq::recv_flags::none);
  }

  return 0;
}
