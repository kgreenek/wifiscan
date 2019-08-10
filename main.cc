#include <iostream>

#include "wifi_scan.h"

int main(int argc, char *argv[]) {
  auto wifi = wifi_scan_init("wlp3s0");
  while (true) {
    struct bss_info bss[100];
    auto status = wifi_scan_all(wifi, bss, 100);
    if (status > 0) {
      std::cout << "-----------------------------" << std::endl;
    }
    for (auto i = 0; i < status && i < 100; ++i) {
      if (std::string(bss[i].ssid).find("meow") == std::string::npos) {
        continue;
      }
      std::cout << bss[i].ssid << " signal " << bss[i].signal_mbm / 100
                << " dBm on " << bss[i].frequency << " MHz seen "
                << bss[i].seen_ms_ago << " ms ago status "
                << (bss[i].status == BSS_ASSOCIATED ? "associated" : "")
                << std::endl;
      // printf("%s signal %d dBm on %u MHz seen %d ms ago status %s\n",
      //       bss[i].ssid, bss[i].signal_mbm / 100, bss[i].frequency,
      //       bss[i].seen_ms_ago,
      //       (bss[i].status == BSS_ASSOCIATED ? "associated" : ""));
    }
  }
  wifi_scan_close(wifi);
}
