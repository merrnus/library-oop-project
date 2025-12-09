#include "../include/AudioBook.h"

// Constructor
AudioBook::AudioBook(const std::string& title, const Author& narrator,
                     int year, int durationMinutes, const std::string& format)
    : Item(title, year), narrator(narrator), 
      durationMinutes(durationMinutes), format(format) {
    std::cout << "AudioBook constructor called for: " << title << "\n";
}

// Copy constructor
AudioBook::AudioBook(const AudioBook& other)
    : Item(other.title, other.year), narrator(other.narrator),
      durationMinutes(other.durationMinutes), format(other.format) {
    std::cout << "AudioBook copy constructor called for: " << title << "\n";
}

// Destructor
AudioBook::~AudioBook() {
    std::cout << "AudioBook destructor called for: " << title << "\n";
}

// Virtual function implementations
void AudioBook::display() const {
    std::cout << "AudioBook: \"" << title << "\", Narrator: " << narrator
              << ", Year: " << year << ", Duration: " << durationMinutes 
              << " min, Format: " << format;
}

AudioBook* AudioBook::clone() const {
    return new AudioBook(*this);
}

std::string AudioBook::getType() const {
    return "AudioBook";
}

double AudioBook::calculateLateFee(int days) const {
    // AudioBooks: 0.4 lei per day (between magazines and books)
    return days * 0.4;
}

// Getters
const Author& AudioBook::getNarrator() const {
    return narrator;
}

int AudioBook::getDuration() const {
    return durationMinutes;
}

const std::string& AudioBook::getFormat() const {
    return format;
}