#ifndef BinaryMassenger_h
#define BinaryMassenger_h

#include "Massenger.h"

/// Main BinaryMassenger class.
class BinaryMassenger : public Massenger
{
public:
  /// Constructor.
  BinaryMassenger(Stream* stream=&Serial);

  /// Flushes current message in buffer (if any).
  virtual void flush();

  /// Reads next byte.
  virtual int8_t nextByte(bool* error=0);

  /// Reads next int.
  virtual int16_t nextInt(bool* error=0);

  /// Reads next long.
  virtual int32_t nextLong(bool* error=0);

  /// Reads next float.
  virtual float nextFloat(bool* error=0);

  /// Reads next double.
  virtual double nextDouble(bool* error=0);

  /// Begins the sending of a message.
  virtual void sendBegin(const char* address);

  /// Sends a byte.
  virtual void sendByte(uint8_t value);

  /// Sends an int.
  virtual void sendInt(int16_t value);

  /// Sends a long.
  virtual void sendLong(int32_t value);

  /// Sends a float.
  virtual void sendFloat(float value);

  /// Sends a double.
  virtual void sendDouble(double value);

  /// Ends the sending of a message.
  virtual void sendEnd();

  /// Sends message with no arguments.
  virtual void send(const char *address);

  /// Sends message with single byte value.
  virtual void sendByte(const char *address, uint8_t value);

  /// Sends message with single int value.
  virtual void sendInt(const char *address, int16_t value);

  /// Sends message with single long value.
  virtual void sendLong(const char *address, int32_t value);

  /// Sends message with single float value.
  virtual void sendFloat(const char *address, float value);

  /// Sends message with single double value.
  virtual void sendDouble(const char *address, double value);

protected:
  /// Processes a single value read from the serial stream.
  virtual bool _process(int serialByte);

private:
  // Moves nextIndex to the next token.
  bool _updateNextIndex();

  // Returns true iff it is still possible to call next*().
  bool _hasNext() const;

  // Helper function to read next block of data.
  void _nextBlock(uint8_t* value, size_t n, bool* error);

  // Sends *n* bytes of *data* to serial using SLIP.
  void _sendSlipData(void* data, size_t n);

  // Index in the buffer of next argument to read.
  uint8_t _nextIndex;

  // SLIP decoding state: currently escaping.
  bool _slipEscaping;
};

#endif
