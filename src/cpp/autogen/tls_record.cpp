// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "tls_record.h"

#include <iostream>
#include <fstream>

tls_record_t::tls_record_t(kaitai::kstream *p_io, kaitai::kstruct *p_parent, tls_record_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = this;
    m_message_type = static_cast<tls_record_t::tls_message_type_t>(m__io->read_u1());
    m_version = new version_t(m__io, this, m__root);
    m_len = m__io->read_u2be();
    m_payload = m__io->read_bytes(len());
}

tls_record_t::~tls_record_t() {
    delete m_version;
}

tls_record_t::version_t::version_t(kaitai::kstream *p_io, tls_record_t *p_parent, tls_record_t *p_root) : kaitai::kstruct(p_io) {
    m__parent = p_parent;
    m__root = p_root;
    m_major = m__io->read_u1();
    m_minor = m__io->read_u1();
}

tls_record_t::version_t::~version_t() {
}
