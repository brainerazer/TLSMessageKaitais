meta:
  id: tls_handshake_record
  endian: be

seq:
  - id: handshake_type
    type: u1
    enum: handshake_type

  - id: len
    type: b24

  - id: payload
    size: len
        
enums:
  handshake_type:
    0: hello_request
    1: client_hello
    2: server_hello
    11: certificate
    12: server_key_exchange
    13: certificate_request
    14: server_hello_done 
    15: certificate_verify
    16: client_key_exchange
    20: finished

