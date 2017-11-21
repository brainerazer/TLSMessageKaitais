#include "catch.hpp"

#include <kaitai/kaitaistream.h>
#include <autogen/tls_record.h>

#include <fstream>
#include <iostream>

TEST_CASE("Files are parsed correctly") {
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
}
