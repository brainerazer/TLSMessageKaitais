#ifndef TLS_HANDSHAKE_RECORD_H_
#define TLS_HANDSHAKE_RECORD_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <kaitai/kaitaistruct.h>
#include <kaitai/kaitaistream.h>

#include <stdint.h>
#include <vector>
#include <sstream>

#if KAITAI_STRUCT_VERSION < 7000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.7 or later is required"
#endif

class tls_handshake_record_t : public kaitai::kstruct {

public:

    enum handshake_type_t {
        HANDSHAKE_TYPE_HELLO_REQUEST = 0,
        HANDSHAKE_TYPE_CLIENT_HELLO = 1,
        HANDSHAKE_TYPE_SERVER_HELLO = 2,
        HANDSHAKE_TYPE_CERTIFICATE = 11,
        HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE = 12,
        HANDSHAKE_TYPE_CERTIFICATE_REQUEST = 13,
        HANDSHAKE_TYPE_SERVER_HELLO_DONE = 14,
        HANDSHAKE_TYPE_CERTIFICATE_VERIFY = 15,
        HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE = 16,
        HANDSHAKE_TYPE_FINISHED = 20
    };

    tls_handshake_record_t(kaitai::kstream* p_io, kaitai::kstruct* p_parent = 0, tls_handshake_record_t* p_root = 0);
    ~tls_handshake_record_t();

private:
    handshake_type_t m_handshake_type;
    uint64_t m_len;
    std::string m_payload;
    tls_handshake_record_t* m__root;
    kaitai::kstruct* m__parent;

public:
    handshake_type_t handshake_type() const { return m_handshake_type; }
    uint64_t len() const { return m_len; }
    std::string payload() const { return m_payload; }
    tls_handshake_record_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // TLS_HANDSHAKE_RECORD_H_
