#include "checklog.h"

void GenerateSegmentationFault() {
  static char* kSegmentFaultCauser = "Used to cause segmentation fault";
  *(char*)((unsigned long)kSegmentFaultCauser << 5) = '\0';
}
