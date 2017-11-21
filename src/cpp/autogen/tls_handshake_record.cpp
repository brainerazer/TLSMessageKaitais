// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "tls_handshake_record.h"

#include <iostream>
#include <fstream>

tls_handshake_record_t::tls_handshake_record_t(kaitai::kstream *p_io, kaitai::kstruct *p_parent, tls_handshake_record_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = this;
    m_handshake_type = static_cast<tls_handshake_record_t::handshake_type_t>(m__io->read_u1());
    m_len = m__io->read_bits_int(24);
    m__io->align_to_byte();
    m_payload = m__io->read_bytes(len());
}

tls_handshake_record_t::~tls_handshake_record_t() {
}
