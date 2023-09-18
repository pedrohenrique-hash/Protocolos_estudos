import socket

def address_ip(host_name):
    
    try:
    
        address = socket.gethostbyaddr(host_name)
    
        return address
    
    except socket.gaierror:
    
        return "ERROR"



if __name__ == "__name__":

    host_name = "https://www.google.com.br/"
    
    address_ip =  address_ip(host_name)

    print(f"Nome do e IP {host_name}  O codigo {address_ip}")
    