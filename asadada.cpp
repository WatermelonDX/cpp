#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>

// Retorna un hash de 32 bits usando Chunked XOR
uint32_t chunkedXORHash32(const std::string& input) {
    uint32_t hash_value = 0;
    size_t i = 0;
    
    // 1. Procesar bloques completos de 4 bytes (32 bits)
    while (i + 4 <= input.length()) {
        uint32_t chunk;
        // Copia 4 bytes directamente de la cadena a un entero de 32 bits
        std::memcpy(&chunk, &input[i],4);
        hash_value ^= chunk;
        i += 4;
    }
    
    // 2. Procesar los bytes sobrantes (Relleno / Padding con ceros)
    if (i < input.length()) {
        uint32_t chunk = 0;
        // Copia los bytes restantes (entre 1 y 3 bytes)
        std::memcpy(&chunk, &input[i], input.length() - i);
        hash_value ^= chunk;
    }
    
    return hash_value;
}

int main() {
    std::string data = "Hello World!"; // 12 bytes = exactamente 3 bloques de 32 bits
    uint32_t hash = chunkedXORHash32(data);
    
    std::cout << "Texto: " << data << std::endl;
    std::cout << "Hash (Hex): 0x" << std::hex << hash << std::endl;
    
    return 0;
}
