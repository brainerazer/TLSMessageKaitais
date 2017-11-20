meta:
  id: tls_record
  endian: be

seq:
  - id: message_type
    type: u1
    enum: tls_message_type

  - id: version
    type: version

  - id: len
    type: u2

  - id: payload
    size: len

types:
  version:
    seq:
      - id: major
        type: u1

      - id: minor
        type: u1
        
enums:
  tls_message_type:
    20: change_cipher_spec
    21: alert
    22: handshake
    23: application_data

