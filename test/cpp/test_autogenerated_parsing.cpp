#include "catch.hpp"

#include <kaitai/kaitaistream.h>
#include <autogen/tls_record.h>
#include <autogen/tls_handshake_record.h>

#include <fstream>
#include <iostream>

TEST_CASE("Entities are parsed correctly on their own") {
    SECTION("Record is parsed correctly") {
        std::ifstream ifs("../sample_data/tls_record_handshake_client_hello.bin", std::ifstream::binary);
        kaitai::kstream ks(&ifs);
        tls_record_t rec = tls_record_t(&ks);

        REQUIRE(rec.version()->major() == 3);
        REQUIRE(rec.version()->minor() == 1);
        REQUIRE(rec.len() == 313);

        REQUIRE(rec.payload()[0] == 1);
        REQUIRE(rec.payload().size() == rec.len());
        REQUIRE(rec.payload()[rec.payload().size() - 1] == 3);
    }

    SECTION("Handshake is parsed correctly") {
        std::ifstream ifs("../sample_data/tls_handshake_client_hello.bin", std::ifstream::binary);
        kaitai::kstream ks(&ifs);
        tls_handshake_record_t hs = tls_handshake_record_t(&ks);

        REQUIRE(hs.handshake_type() == tls_handshake_record_t::HANDSHAKE_TYPE_CLIENT_HELLO);
        REQUIRE(hs.len() == 309);

        REQUIRE(hs.payload()[0] == 3);
        REQUIRE(hs.payload().size() == hs.len());
        REQUIRE(hs.payload()[hs.payload().size() - 1] == 3);
    }
}

TEST_CASE("Entities are parsed correctly together") {
    SECTION("Handshake from Record is parsed correctly") {
        std::ifstream ifs("../sample_data/tls_record_handshake_client_hello.bin", std::ifstream::binary);
        kaitai::kstream ks(&ifs);
        tls_record_t rec = tls_record_t(&ks);
        std::string pl_copy(rec.payload());
        kaitai::kstream hks(pl_copy);
        tls_handshake_record_t hs = tls_handshake_record_t(&hks);

        REQUIRE(hs.payload()[0] == 3);
        REQUIRE(hs.payload().size() == hs.len());
        REQUIRE(hs.payload()[hs.payload().size() - 1] == 3);
    }
}
