
# Vulnerable C++ Project for SBOM/SCA Testing

This project demonstrates usage of outdated third-party libraries with known CVEs:

- **OpenSSL < 1.1.1k** (e.g., CVE-2021-3449)
- **libcurl < 7.80.0** (e.g., CVE-2021-22946)
- **zlib < 1.2.12** (e.g., CVE-2018-25032)


- **libxml2 < 2.10.3** (e.g., CVE-2022-40303)
- **SQLite < 3.39.2** (e.g., CVE-2022-35737)
- **expat < 2.4.9** (e.g., CVE-2022-40674)

## Setup

Use CMake to build the project. Ensure you link against outdated versions of the libraries.

```bash
mkdir build && cd build
cmake ..
make
./vulnerable_cpp
```

## SBOM Generation

You can use tools like [Syft](https://github.com/anchore/syft) or [CycloneDX](https://github.com/CycloneDX/cyclonedx-cpp) to generate SBOMs.

```bash
syft . -o cyclonedx-json > sbom.json
```
