import network
import socket
from machine import Pin

# Pin configuration
light1 = Pin(16, Pin.OUT)
light2 = Pin(17, Pin.OUT)
fan1 = Pin(18, Pin.OUT)
fan2 = Pin(19, Pin.OUT)

# Connect to Wi-Fi
ssid = 'Your_SSID'
password = 'Your_PASSWORD'

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    
    while not wlan.isconnected():
        pass
    print('Connected to WiFi')
    print('IP address:', wlan.ifconfig()[0])

# HTML for the webpage with added CSS for better styling
def web_page():
    html = """
    <html>
        <head>
            <title>ESP32 Control</title>
            <style>
                body { 
  font-family: Arial;
  display: flex;
  justify-content: 
  center; align-items:
  center; height: 100vh; 
  margin: 0;
  background-color: #f0f0f0; }
                .container { text-align: center; }
                h2 { color: #333; }
                a { text-decoration: none; padding:
                  10px 20px; display: 
                  inline-block;
                  margin: 10px; 
                  background-color: #4CAF50; 
                  color: white; 
                  border-radius: 5px; }
                a:hover { background-color: #45a049; }
                .button-off { background-color: #f44336; }
                a.button-off:hover { background-color: #e53935; }
            </style>
        </head>
        <body>
            <div class="container">
                <h2>ESP32 Web Server</h2>
                <p><a href="/light1/on">Turn ON Light 1</a></p>
                <p><a href="/light1/off" class="button-off">Turn OFF Light 1</a></p>
                <p><a href="/light2/on">Turn ON Light 2</a></p>
                <p><a href="/light2/off" class="button-off">Turn OFF Light 2</a></p>
                <p><a href="/fan1/on">Turn ON Fan 1</a></p>
                <p><a href="/fan1/off" class="button-off">Turn OFF Fan 1</a></p>
                <p><a href="/fan2/on">Turn ON Fan 2</a></p>
                <p><a href="/fan2/off" class="button-off">Turn OFF Fan 2</a></p>
            </div>
        </body>
    </html>
    """
    return html

# Handle the web server requests
def serve_client(client):
    request = client.recv(1024).decode('utf-8')
    print('Request:', request)

    # Handling the requests for lights and fans
    if '/light1/on' in request:
        light1.on()
    if '/light1/off' in request:
        light1.off()
    if '/light2/on' in request:
        light2.on()
    if '/light2/off' in request:
        light2.off()
    if '/fan1/on' in request:
        fan1.on()
    if '/fan1/off' in request:
        fan1.off()
    if '/fan2/on' in request:
        fan2.on()
    if '/fan2/off' in request:
        fan2.off()

    # Sending the response back to the client
    client.send('HTTP/1.1 200 OK\n')
    client.send('Content-Type: text/html\n')
    client.send('Connection: close\n\n')
    client.sendall(web_page())
    client.close()

# Main function
def main():
    connect_wifi()

    # Create a socket and bind to port 80
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', 80))
    s.listen(5)

    while True:
        client, addr = s.accept()
        print('Client connected from', addr)
        serve_client(client)

# Run the program
main()
