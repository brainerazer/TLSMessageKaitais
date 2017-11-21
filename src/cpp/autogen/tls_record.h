#ifndef TLS_RECORD_H_
#define TLS_RECORD_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <kaitai/kaitaistruct.h>
#include <kaitai/kaitaistream.h>

#include <stdint.h>
#include <vector>
#include <sstream>

#if KAITAI_STRUCT_VERSION < 7000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.7 or later is required"
#endif

class tls_record_t : public kaitai::kstruct {

public:
    class version_t;

    enum tls_message_type_t {
        TLS_MESSAGE_TYPE_CHANGE_CIPHER_SPEC = 20,
        TLS_MESSAGE_TYPE_ALERT = 21,
        TLS_MESSAGE_TYPE_HANDSHAKE = 22,
        TLS_MESSAGE_TYPE_APPLICATION_DATA = 23
    };

    tls_record_t(kaitai::kstream* p_io, kaitai::kstruct* p_parent = 0, tls_record_t* p_root = 0);
    ~tls_record_t();

    class version_t : public kaitai::kstruct {

    public:

        version_t(kaitai::kstream* p_io, tls_record_t* p_parent = 0, tls_record_t* p_root = 0);
        ~version_t();

    private:
        uint8_t m_major;
        uint8_t m_minor;
        tls_record_t* m__root;
        tls_record_t* m__parent;

    public:
        uint8_t major() const { return m_major; }
        uint8_t minor() const { return m_minor; }
        tls_record_t* _root() const { return m__root; }
        tls_record_t* _parent() const { return m__parent; }
    };

private:
    tls_message_type_t m_message_type;
    version_t* m_version;
    uint16_t m_len;
    std::string m_payload;
    tls_record_t* m__root;
    kaitai::kstruct* m__parent;

public:
    tls_message_type_t message_type() const { return m_message_type; }
    version_t* version() const { return m_version; }
    uint16_t len() const { return m_len; }
    std::string payload() const { return m_payload; }
    tls_record_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // TLS_RECORD_H_
