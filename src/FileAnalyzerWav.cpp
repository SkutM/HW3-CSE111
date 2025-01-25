#include "FileAnalyzerWav.h"

FileAnalyzerWav::FileAnalyzerWav(const std::string& filename)
    : FileAnalyzerFile(filename, {".wav"}) {}

int FileAnalyzerWav::GetBitrate() const {
    int sample_rate = ReadLittleEndianInt32(24);
    int num_channels = ReadLittleEndianInt16(22);
    int bits_per_sample = ReadLittleEndianInt16(34); 

    std::cout << "Sample rate: " << sample_rate << "\n";
    std::cout << "Num channels: " << num_channels << "\n";
    std::cout << "Bits per sample: " << bits_per_sample << "\n";

    return sample_rate * num_channels * bits_per_sample / 8;
}

int FileAnalyzerWav::GetChannels() const {
    return ReadLittleEndianInt16(22);
}
