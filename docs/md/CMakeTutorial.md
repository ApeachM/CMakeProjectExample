# CMake Tutorial

## Introduction

**CMake 소개: Makefile에서 벗어나, 더 큰 세계로**

CMake는 고급 빌드 시스템으로, 복잡한 프로젝트 구조와 다양한 개발 환경을 가진 프로젝트의 빌드를 단순화하고자 개발되었습니다. 전통적인 Makefile 시스템과 달리, CMake는 프로젝트의 구조와 빌드 과정을 기술하는 더 높은 수준의 구성 파일을 사용합니다. 이러한 접근 방식은 여러 운영 체제와 컴파일러에서의 이식성과 호환성을 크게 향상시킵니다.

**1. 크로스 플랫폼 호환성**

CMake의 가장 큰 장점 중 하나는 다양한 플랫폼(Windows, macOS, Linux 등)과 컴파일러에 걸쳐 일관된 빌드 환경을 제공한다는 것입니다. 즉, CMake는 사용자가 작성한 구성 파일을 바탕으로 해당 플랫폼에 최적화된 Makefile이나 프로젝트 파일을 생성합니다. 이는 프로젝트를 여러 환경에 걸쳐 쉽게 이식할 수 있게 해주며, 개발자는 복잡한 환경 설정에 신경 쓰지 않고도 작업에 집중할 수 있습니다.

**2. 유지 보수의 용이성**

전통적인 Makefile 시스템에서는 프로젝트가 성장함에 따라 Makefile을 유지 보수하기가 점점 더 어려워집니다. 반면, CMake는 프로젝트의 의존성과 빌드 규칙을 명확하고 간결하게 표현할 수 있도록 돕습니다. CMakeLists.txt 파일 한 개로 프로젝트의 전체 빌드 과정을 관리할 수 있으며, 이는 프로젝트의 복잡성이 증가해도 유지 보수를 쉽게 할 수 있게 해줍니다.

**3. 모듈성과 재사용성**

CMake는 프로젝트를 모듈 단위로 나누어 관리할 수 있게 해주며, 이는 대규모 프로젝트의 개발과 협업에 매우 유용합니다. 라이브러리나 애플리케이션 구성 요소를 CMake의 타겟으로 정의하면, 이들 간의 의존성을 쉽게 관리할 수 있고, 필요한 경우 재사용도 가능합니다.

**4. 강력한 테스트와 패키징 기능**

CMake는 CTest & GTest, 그리고 CPack이라는 강력한 테스팅과 패키징 도구를 내장하고 있습니다. 이를 통해 개발자는 소프트웨어의 품질을 지속적으로 관리하고, 다양한 플랫폼과 환경에서 쉽게 배포할 수 있는 패키지를 생성할 수 있습니다.

**결론**

CMake는 현대적인 소프트웨어 개발 환경에서 필수적인 도구 중 하나입니다. 기존의 Makefile만 사용해오신 분들이라면, CMake의 유연성, 이식성 및 확장성을 경험하면서 프로젝트 관리의 새로운 지평을 열 수 있을 것입니다. 시작하기 위해선 공식 문서와 다양한 튜토리얼을 참고하는 것이 좋으며, 이 과정을 통해 더욱 효율적이고 체계적인 빌드 환경을 구축할 수 있을 것입니다.



## 가장 간단한 CMake 파일의 예시

### Commit Version

> 아래 커밋으로 Check Out 하시면 현재 섹션을 Run할 수 있습니다.
>

- Hash Value: ` a9c13693`
- Commit Name: [ADD] Add the most simple example for `CMakeLists.txt`

### CMakeFile.txt 파일

**CMakeLists.txt** 파일은 CMake 프로젝트의 설정 파일로, 프로젝트의 빌드 방식을 정의합니다. 다음은 간단한 C++ 프로젝트를 위한 기본적인 CMake 구성 예시입니다:

```cmake
cmake_minimum_required(VERSION 3.20)
project(CppProjectTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(my_project src/main.cpp)
```

이것은 C++ 프로젝트를 위한 가장 간단한 CMakeLists.txt 파일의 예시로, 프로젝트 설정과 빌드 명령을 포함합니다. 각 구성 요소에 대한 설명은 다음과 같습니다:

### 각 구성 요소에 대한 설명

1. **CMake 최소 버전 지정:**
   
   ```cmake
   cmake_minimum_required(VERSION 3.20)
   ```
   이 명령은 CMake의 최소 요구 버전을 지정합니다. 이는 현재 CMake 스크립트가 사용하는 기능이 지정된 버전 이상에서만 사용 가능함을 보장합니다.
   
2. **프로젝트 이름 설정:**
   
   ```cmake
   project(CppProjectTemplate)
   ```
   `project` 명령은 프로젝트의 이름을 설정합니다. 여기서는 `CppProjectTemplate`이 프로젝트의 이름으로 사용됩니다.
   
   > 이 이름은 프로젝트의 식별자 역할을 하며, CMake 내에서 또는 프로젝트를 참조할 때 사용할 수 있습니다. 예를 들어, 프로젝트 이름을 바탕으로 특정 설정이나 변수를 조건부로 적용할 수 있습니다. `CppProjectTemplate` 같은 프로젝트 이름은 다음과 같은 상황에서 유용하게 쓰입니다:
   >
   > - **빌드 구성**: 프로젝트 이름을 사용하여 빌드 구성을 커스터마이징할 수 있습니다. 예를 들어, 다른 프로젝트 이름에 따라 다른 컴파일러 플래그나 옵션을 적용할 수 있습니다.
   > - **로깅 및 진단**: 빌드 프로세스 중에 프로젝트 이름을 로깅에 사용하여, 어떤 프로젝트의 빌드 과정인지 쉽게 식별할 수 있게 합니다.
   > - **하위 프로젝트 관리**: 큰 프로젝트 내에서 여러 하위 프로젝트를 관리할 때, 각각의 하위 프로젝트에 고유한 이름을 부여하여 관리와 참조를 용이하게 합니다.
   > - **패키지 및 배포**: 프로젝트 이름은 종종 빌드된 소프트웨어의 최종 패키지 이름이나 설치 경로에 사용됩니다. 이를 통해 배포 과정을 더 명확하게 관리할 수 있습니다.
   >
   > 간단히 말해, `CppProjectTemplate`는 프로젝트에 대한 이름표 역할을 하며, 프로젝트의 설정, 관리, 배포 등 다양한 맥락에서 참조됩니다. 프로젝트의 이름은 프로젝트의 성격, 용도, 버전 등을 반영하여 선택하는 것이 일반적입니다.
   
3. **C++ 표준 설정:**
   
   ```cmake
   set(CMAKE_CXX_STANDARD 17)
   set(CMAKE_CXX_STANDARD_REQUIRED True)
   ```
   이 세트는 프로젝트에서 사용할 C++ 표준 버전을 지정합니다. 여기서는 C++17 표준을 사용하도록 설정하고 있으며, `CMAKE_CXX_STANDARD_REQUIRED`를 `True`로 설정함으로써, 이 표준을 반드시 준수하도록 요구합니다.
   
4. **실행 파일 추가:**
   
   ```cmake
   add_executable(my_project src/main.cpp)
   ```
   `add_executable` 명령은 빌드할 실행 파일의 이름과 소스 파일을 지정합니다. 이 경우, `my_project`라는 이름의 실행 파일을 생성하며, 빌드에는 `src/main.cpp` 파일이 사용됩니다.

## CMake 프로젝트 실행 및 빌드 방법

### 기본 빌드 방법

위 간단한 `CMake` 설정파일과 함께 빌드를 실행해보도록 하겠습니다.  빌드 과정을 시작하기 위해서는 기본적으로 두 단계의 명령어를 사용합니다. 또한, 이 과정을 자동화하기 위해 `scripts/runCMake.sh` 스크립트를 실행하는 옵션도 있습니다. 

먼저, CMake 구성 파일의 위치를 지정하고 빌드 디렉토리를 설정하기 위해 다음 명령어를 사용합니다:

```shell
cmake -S . -B build
```

여기서 `-S` 옵션은 CMake 구성 파일(`CMakeLists.txt`)이 위치한 디렉토리를 나타내며, `-B` 옵션은 빌드 파일들이 생성될 디렉토리를 지정합니다. 본 예시에서는 현재 디렉토리(`.`)를 소스 디렉토리로 하고, `build` 디렉토리를 빌드 디렉토리로 사용합니다.

다음으로, 설정된 빌드 디렉토리에서 실제 빌드 프로세스를 실행하기 위해 아래 명령어를 입력합니다:

```shell
cmake --build build
```

이 명령어는 CMake를 통해 생성된 빌드 시스템을 실행하며, `build` 디렉토리 내의 모든 필요한 컴파일 및 링크 과정을 자동으로 처리합니다. 이 과정은 기존의 `make` 명령어와 유사하게 작동합니다.

### GENERATOR 설정

`make`가 아닌 다른 빌드 Generator을 사용하면 조금 더 빠르게 컴파일이 가능합니다. `Ninja`, `Ninja Multi-Config`, `Watcom WMake`, `Unix Makefile` 등 많은 Generator가 있으며, 해당 Generator를 사용하기 위해서는 다음과 같이 첫번째 명령어를 바꾸어 사용하시면 됩니다. 아래는 Ninja를 이용한 빌드를 위한 명령어입니다.

```shell
cmake -S . -B build -G Ninja
# cmake -S . -B build -G "Ninja Multi-Config"
# cmake -S . -B build -G "Watcom WMake"
cmake --build build
```

1. **Ninja**: Ninja는 빠른 빌드 시스템으로, 중소 규모에서 큰 규모의 소프트웨어 프로젝트에 이르기까지 다양한 개발 프로젝트의 빌드 속도를 개선하기 위해 설계되었습니다. Ninja는 특히 재빌드 시간을 최소화하는 데 초점을 맞추고 있으며, 다른 빌드 시스템보다 더 빠른 성능을 제공하기 위해 최적화되어 있습니다. CMake와 같은 다른 빌드 시스템과 함께 사용될 수 있습니다.
2. **Ninja Multi-Config**: Ninja Multi-Config는 Ninja 빌드 시스템의 확장 기능으로, 단일 소스 트리에서 여러 구성(예: 디버그, 릴리스)을 동시에 관리할 수 있도록 도와줍니다. 이는 크로스-플랫폼 개발 환경에서 특히 유용하며, 개발자가 다양한 플랫폼 또는 구성에 대해 동시에 빌드를 관리하고 실행할 수 있게 해줍니다.
3. **Watcom WMake**: Watcom WMake은 Open Watcom 프로젝트의 일부로, 고성능 컴파일러와 툴체인을 제공하는 소프트웨어입니다. WMake은 Make 유틸리티의 변형으로, 소프트웨어 빌드 프로세스를 자동화하는 데 사용됩니다. 특히, 다중 플랫폼을 지원하며, 복잡한 빌드 환경에서도 사용하기 용이하도록 설계되었습니다.

> 해당 Generator 툴들은 `Debian` 계열 linux라면 `sudo apt install Ninja` 와 같은 방식으로, `Fedora` 계열 linux라면 `sudo dnf install Ninja` 와 같이 설치하시면 사용하실 수 있습니다.



### BUILD TYPE 설정

**Release**, **Debug**, **RelWithDebInfo (Release with Debug Info)**, **MinSizeRel (Minimum Size Release)** 와 같은 빌드 타입을 `CMake`에서는 한번에 설정이 가능합니다. `CMake`를 실행할 때 아래와 같이 명령어를 실행하여 변수 설정을 해주면 전체 빌드 설정이 완료되며, shell level이 아닌 `CMake`에 직접적으로 변수 설정을 할 수도 있습니다. 아래는 Ninja를 사용하고, Release 형태로 빌드를 하기 위한 명령어입니다.

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release 
#cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
#cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo 
#cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=MinSizeRel 
cmake --build build
```

또는 실행시 `-DCMAKE_BUILD_TYPE` 변수 없이 CMake에 다음과 같이 설정해주면 간단히 설정될 수 있습니다.

```cmake
cmake_minimum_required(VERSION 3.20)
project(CppProjectTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release) # set the build type here

add_executable(my_project src/main.cpp)
```

각 빌드 타입에 대한 간단한 설명은 아래와 같습니다.

1. **Release**:
   - 최적화 옵션을 활성화하여 최대한 성능을 높인 상태로 컴파일합니다.
   - 디버깅 정보를 포함하지 않아, 최종 사용자에게 배포하기에 적합한 바이너리가 생성됩니다.
2. **Debug**:
   - 최적화를 수행하지 않고, 디버깅 심볼을 포함하여 컴파일합니다.
   - 이를 통해 개발자는 프로그램의 실행을 디버깅하고, 문제의 원인을 보다 쉽게 찾을 수 있습니다.
3. **RelWithDebInfo (Release with Debug Info)**:
   - 최적화는 활성화하되, 디버깅 정보도 포함하여 컴파일합니다.
   - 이는 성능은 최적화하면서도 필요 시 디버깅이 가능하게 하려는 경우에 유용합니다.
   - `RelWithDebInfo` (Release with Debug Information) 빌드 타입은 Release와 Debug 사이의 "중간 지점"을 제공합니다.
4. **MinSizeRel (Minimum Size Release)**:
   - 바이너리의 크기를 최소화하는 최적화를 수행하며, 디버깅 정보는 포함하지 않습니다.
   - 이 빌드 타입은 저장 공간이 제한적인 환경에 배포할 때 유용합니다.



### 추신: 빌드 자동화 스크립트 실행하기

빌드 과정을 더욱 간편하게 만들기 위해, `scripts/runCMake.sh` 스크립트를 사용할 수 있습니다. 이 스크립트는 위에서 설명한 두 단계의 명령어를 하나의 과정으로 자동화해 줍니다. 스크립트를 실행하기 위해서는 단순히 다음과 같이 입력하면 됩니다:

```shell
bash scripts/runCMake.sh
```

이 방법을 사용하면 사용자는 복잡한 명령어를 직접 입력할 필요 없이, 빌드 프로세스를 쉽게 시작할 수 있습니다.

해당 과정을 거치면, `build` 폴더 안에 Makefile과 CMake을 위한 여러 설정 파일, 그리고 바이너리 파일을 보실 수 있습니다.



## Header File 경로 설정

프로젝트의 구조를 변경하여 기능을 별도의 파일로 분리하고, 이를 CMake를 사용해 빌드하는 과정을 안내 드리겠습니다. 이 변경은 코드의 모듈성을 향상시키고, 재사용성을 높이며, 프로젝트의 관리를 용이하게 합니다. CMake 구성 파일을 업데이트하여 이러한 구조 변경을 반영하는 방법을 아래에 설명하겠습니다.

### Commit Version

- Hash Value: `7db0e8f2`
- Commit Name: [ADD] Add the explanation for `target_include_libraries`

### 프로젝트 파일 구조 변경

기존에는 `main.cpp` 파일 내에 모든 코드가 포함되어 있었습니다. 이제는 `add` 함수와 `subtract` 함수를 `myFunction.cpp`와 `myFunction.h` 파일로 분리하여, 함수의 정의와 선언을 별도의 파일에 위치시킵니다. 헤더파일은 헤더파일 경로 설정의 예시를 위하여 `includ` 폴더 안에 위치하도록 하겠습니다. 이렇게 하면, 함수들을 다른 파일에서도 쉽게 재사용할 수 있게 됩니다.

- `main.cpp`: 프로그램의 진입점으로, `myFunction.h` 헤더를 포함하여 `add` 함수를 사용합니다.
- `myFunction.cpp`: `add`와 `subtract` 함수의 구현을 포함합니다.
- `myFunction.h`: `add`와 `subtract` 함수의 선언을 포함하여, 이 함수들이 다른 파일에서도 사용될 수 있게 합니다.

### CMake 설정 업데이트

CMake 구성 파일 `CMakeLists.txt`를 업데이트하여, 새로운 소스 파일(`myFunction.cpp`)과 헤더 파일의 위치(`myFunction.h`)를 프로젝트에 포함시켜야 합니다.

```cmake
add_executable(my_project
        src/main.cpp
        src/myFunction.cpp
)
```

- `add_executable` 명령은 `my_project` 실행 파일을 생성할 때 `src/main.cpp`와 `src/myFunction.cpp` 두 소스 파일을 컴파일 대상에 포함시킵니다. 이는 프로젝트의 실행 파일이 이 두 파일의 코드를 필요로 함을 CMake에 알립니다.

```cmake
target_include_directories(my_project
        PUBLIC
        include
)
```

- `target_include_directories` 명령은 `my_project` 타겟(실행 파일)을 빌드할 때 컴파일러에게 헤더 파일의 위치를 알려줍니다.  여기서는 헤더파일이 존재하는 `include` 디렉토리가 헤더 파일을 찾을 위치로 지정되어 있습니다. 

- `PUBLIC` 지정자는 이 헤더 파일들이 `my_project` 타겟뿐만 아니라, 이 프로젝트를 참조하는 다른 타겟에도 사용될 수 있음을 의미합니다.

  > 만약 `PRIVATE` 지정자를 사용하면 해당 설정이 타겟에 직접 적용되며, 타겟이 다른 타겟에 연결될 때 해당 설정이 전파되지 않습니다. 
  >
  > 구체적으로 `target_include_directories` 명령에 `PRIVATE`를 사용하는 경우, 해당 헤더 파일 경로는 오직 해당 타겟의 컴파일에만 사용되며, 이 타겟을 `target_link_libraries` 등을 통해 다른 타겟에 연결해도 헤더 파일 경로가 전파되지 않습니다.
  > `target_link_libraries`에 대해서는 이후 섹션에서 소개해드리겠습니다.

- 만약 모든 컴파일이 해당 헤더파일 경로를 인식하도록 설정하고 싶다면 다음 명령어를 사용하면 됩니다. 하지만 이는 전역변수 설정과 같은 맥락으로 추천드리지 않습니다.

  ```cmake
  include_directories(include)
  ```

이 변경을 통해, 프로젝트의 코드 구조가 더욱 명확해지고, 함수들이 별도의 파일로 관리됨으로써 코드의 재사용성과 유지보수성이 향상됩니다.

## Library 생성

라이브러리를 생성하고 관리하는 것은 CMake를 사용한 프로젝트 개발의 중요한 부분입니다. 라이브러리를 사용하면 코드의 재사용성을 높이고, 모듈성을 개선하며, 빌드 시간을 최적화할 수 있습니다. CMake에서는 두 가지 주요 유형의 라이브러리를 생성할 수 있습니다: 정적 라이브러리(Static libraries)와 동적 라이브러리(Shared libraries). 여기서는 각각의 생성 방법과 사용 예를 다루겠습니다.

### Commit Version

- Hash Value: `ed6bd6b4`
- Commit Name: [ADD] Add the explanation for `add_library` and `target_link_libraries` 

### 정적 라이브러리(Static Library)

정적 라이브러리는 `.a` 또는 `.lib` 파일로 컴파일되며, 프로그램을 빌드할 때 코드가 직접 프로그램에 포함됩니다. 정적 라이브러리는 실행 파일의 크기를 증가시키지만, 외부 라이브러리에 대한 의존성을 줄이고 배포를 단순화할 수 있습니다.

CMake에서 정적 라이브러리를 생성하는 예시:

```cmake
add_library(my_static_library STATIC
    src/LibraryCode.cpp
)
```

### 동적 라이브러리(Shared Library)

동적 라이브러리는 `.so`, `.dll` 또는 `.dylib` 파일로 컴파일되며, 프로그램 실행 시 로드됩니다. 동적 라이브러리를 사용하면 실행 파일의 크기를 줄일 수 있고, 여러 프로그램이 동일한 라이브러리 인스턴스를 공유할 수 있습니다.

CMake에서 동적 라이브러리를 생성하는 예시:

```cmake
add_library(my_shared_library SHARED
    src/LibraryCode.cpp
)
```


### 라이브러리의 헤더 파일 포함

라이브러리를 사용하는 프로젝트 또는 다른 라이브러리에서 해당 라이브러리의 헤더 파일에 접근할 수 있도록 설정해야 합니다. 이는 `target_include_directories`를 사용하여 라이브러리 타겟에 대해 수행할 수 있습니다.

```cmake
target_include_directories(my_static_library PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
```


### 라이브러리와 실행 파일 연결하기

라이브러리를 생성한 후, 실행 파일과 연결해야 합니다. `target_link_libraries` 명령을 사용하여 이를 수행할 수 있습니다. 예를 들어, 위에서 생성한 `my_static_library` 또는 `my_shared_library`를 `my_project` 실행 파일과 연결하는 방법은 다음과 같습니다:

```cmake
add_executable(my_project src/main.cpp)

# 정적 라이브러리를 연결하는 경우
target_link_libraries(my_project my_static_library)

# 또는 동적 라이브러리를 연결하는 경우
target_link_libraries(my_project my_shared_library)
```

## Flags

CMake에서 Flag는 크게 컴파일을 위한 Flag와 링킹에 대한 Flag로 나뉠 수 있습니다.

### Commit Version

- Hash Value: `c6f8dd2f`
- Commit Name: [ADD] Add the explanation for options and definitions for `CMake` 

### Linking Flag

#### 전역 설정

```cmake
add_link_options("-static")
```

다음과 같이 하면 전체 프로젝트에 대해 "-static"이 link flag로 적용됩니다. 하지만 이는 전역에 대한 설정이므로, 위와 같이 추천드리지 않습니다.

#### 타겟 설정

```cmake
target_link_options(my_project PRIVATE "-static")
```

다음과 같이 하면 `cmake --build build`를 하여 빌드 할 때에 `my_library` 라이브러리와 static으로 빌드가 가능해집니다.

### Compile Flag

#### 전역 설정

```cmake
add_compile_options("-Wall" "-O2")
```

다음과 같이 하면 전체 프로젝트에 대해 "-Wall"과 "-O2"가 compile flag로 적용됩니다. 하지만 이는 전역에 대한 설정이므로, 위와 같이 추천드리지 않습니다.

#### 타겟 설정

```cmake
target_compile_options(my_project PRIVATE "-Wall" "-O2")
```

다음과 같이 하면 `cmake --build build`를 하여 빌드 할 때에 `my_project` binary 컴파일시 해당 플래그와 함께 컴파일 되어, 컴파일 경고메시지를 출력하며 최적화 수준을 2로 맞춰줍니다.

## Compile Definition

### 전역 설정

```cmake
add_compile_definitions("-DLOG_LEVEL=2") 
```

다음과 같이 하면 전체 프로젝트에 대해 "LOG_LEVEL=2"가 compile flag로 적용됩니다. 하지만 이는 전역에 대한 설정이므로, 위와 같이 추천드리지 않습니다.

### 타겟 설정

```cmake
target_compile_definitions(my_project PRIVATE "-DLOG_LEVEL=2")
```

다음과 같이 하면 `cmake --build build`를 하여 빌드 할 때에 `my_project` binary 컴파일시 해당 definition과 함께 컴파일 되어, 전처리시 코드 내에 특정 값을 주입할 수 있습니다.

네, 맞습니다. `add_subdirectory` 명령어를 사용하여 프로젝트 내에서 다른 디렉토리를 추가하고 그 안의 `CMakeLists.txt` 파일을 포함시키는 과정은 CMake를 이용한 프로젝트 모듈화의 일환으로 볼 수 있습니다. 이 방식은 프로젝트의 구조를 더 명확하게 나누고, 재사용 가능한 컴포넌트나 라이브러리를 관리하기 위한 효율적인 방법을 제공합니다.

## CMake 프로젝트 모듈화 

### Commit Version

- Hash Value: `fa038613`
- Commit Name: [ADD] Add the explanation for `add_subdirectory` 

###  장점

1. **재사용성**: 특정 기능이나 라이브러리를 별도의 디렉토리에 구성함으로써, 이를 다른 프로젝트에서도 쉽게 재사용할 수 있습니다.
2. **유지보수성**: 프로젝트의 각 부분을 분리함으로써, 코드의 유지보수가 용이해집니다. 오류 수정, 기능 추가 또는 변경 시 해당 모듈만을 대상으로 작업할 수 있어 전체 프로젝트의 안정성을 유지할 수 있습니다.
3. **가독성 및 관리 용이성**: 큰 프로젝트를 더 작은 단위로 분리함으로써, 프로젝트의 구조를 더 쉽게 이해하고 관리할 수 있습니다.

### add_subdirectory 사용 예시

최상위 `CMakeLists.txt` 파일:
```cmake
cmake_minimum_required(VERSION 3.20)
project(CppProjectTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
```

`src/CMakeLists.txt` 파일:

```cmake
# Make executable file (target)
add_executable(my_project
        src/main.cpp
)

# Make library (target)
add_library(my_library
        STATIC
        myFunction.cpp
)
target_include_directories(my_library
        PUBLIC
        ${CMAKE_SOURCE_DIR}/src
)

# Link binary and library
target_link_libraries(my_project
        PUBLIC
        my_library
)

# Set link option
target_link_options(my_project PRIVATE "-static")

# Set compile option
target_compile_options(my_project PRIVATE "-Wall" "-O2")

# Set compile definitions
target_compile_definitions(my_project PRIVATE "-DLOG_LEVEL=2")
```

- 이 예시에서는 `add_subdirectory`를 사용하여 메인 프로젝트의 `CMakeLists.txt` 파일에서 `src` 디렉토리의 `CMakeLists.txt` 파일을 포함시킵니다. 해당 행위는 라이브러리 단위로 프로젝트를 쪼갤 때 쓰기 더욱 좋습니다.
- `${CMAKE_SOURCE_DIR}` 변수는 최상위 `CMake`파일의 위치를 나타냅니다. 현재 `CMakeList.txt ` 파일의 위치를 나타내고 싶다면 `${CMAKE_CURRENT_SOURCE_DIR}` 변수를 사용하면 되며, 해당과 같은 기본 변수들은 이후 섹션에서 소개시켜드리겠습니다.

## Binary File 및 Library File 위치 지정

### Commit Version

- Hash Value: `fe50ed01`
- Commit Name: [ADD] Add the explanation for `OUTPUT_DIRECTORY` 

### CMake 설정 방법

위와 같이 sub_directory로 `CMake` 파일을 만들게 되면 `build` 파일의 `src` 파일 안에 library 파일과 executable 파일이 들어간 것을 확인하실 수 있습니다.

이는 자동으로 배치된 위치지만, 우리가 원하는 위치에 해당 파일들을 위치시킬 수 있는 방법이 있습니다.

```cmake
# Set the location of library file
# ARCHIVE_OUTPUT_DIRECTORY means the location of static library
# LIBRARY_OUTPUT_DIRECTORY means the location of dynamic library
set_target_properties(my_library PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib"
)
# Set the location of binary file
set_target_properties(my_project PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/bin"
)
```

`set_target_properties` 명령어를 이용하여 `ARCHIVE_OUTPUT_DIRECTORY`, `LIBRARY_OUTPUT_DIRECTORY`를 이용하면 .a 파일이나 .so 파일의 위치를 지정할 수 있으며, `RUNTIME_OUTPUT_DIRECTORY`를 이용하면 binary 파일의 위치를 지정할 수 있습니다.



## 외부 Library 사용법 

### Commit Version

- Hash Value: `1a14fd00`
- Commit Name: [ADD] Add the explanation for importing external package with `find_package` 

### 사용전 외부 Library 설치 방법

`TCL`, `GTest`, `OpenSSL`, `Glog`, `Doxygen` 등 현대 외부 라이브러리들은 대부분 CMake를 지원합니다. 시스템에 해당 라이브러리가 설치되어 있다면, `find_package`라는 CMake 명령어로 손 쉽게 연결이 가능합니다.

예를들어 데비안 계열 (ex. Ubuntu)에서는 다음과 같이 시스템에 설치할 수 있습니다.

```shell
sudo apt-get update
sudo apt-get install libgtest-dev libglog-dev libssl-dev tcl-dev doxygen
```

페도라 계열 (ex. RHEL, CentOS)은 다음과 같이 시스템에 설치할 수 있습니다.

```shell
sudo dnf update
sudo dnf install gtest gtest-devel glog glog-devel openssl openssl-devel tcl tcl-devel doxygen
```

Mac에서는 brew를 이용하여 다음과 같이 설치할 수 있습니다.

```shell
brew update
brew install gtest glog openssl tcl-tk doxygen
```

외부 라이브러리 사용법을 위하여 TCL과 Google Test라는 외부 패키지를 이용하는 것으로 예시를 들어보도록 하겠습니다.

### TCL Importing

CMake 파일에서 다음과 같이 find_package를 하여 Import를 한 후, `link_libraries`에 [설정된 변수](https://cmake.org/cmake/help/latest/module/FindTCL.html)인 `${TCL_LIBRARY}`를 작성해주면 바로 사용할 수 있습니다.

```cmake
# Load the package from the system
# By REQUIRED option, if it is not able to find the tcl in the system, then the loading cmake will be stopped.
find_package(TCL REQUIRED)
# Link binary and library
target_link_libraries(my_project
        PUBLIC
        my_library
        ${TCL_LIBRARY}
)
```

> 특정 라이브러리는 완전한 사용을 위해 동적 컴파일링이 디폴트로 되어있을 수 있습니다. 따라서 `target_link_options(my_project PRIVATE "-static")`와 같은 명령어와 함께 빌드 하였을 때 에러가 날 수 있습니다. 
>
> 이를 위해서, find_package를 사용하지 않고 직접적인 경로를 이용하여 정적 컴파일링을 다음과 같이 수행할 수 있습니다.
>
> ```cmake
> # Link binary and library
> target_link_libraries(my_project
>      PUBLIC
>      my_library
>      /usr/lib/x86_64-linux-gnu/libtcl8.6.a z m dl # for static linking
> )
> 
> # Set link option
> target_link_options(my_project PRIVATE "-static")
> ```
>
> 이렇게 빌드를 하면 `TclpDlopen`, `TclpGetGrGid`등의 함수는 사용하지 못한다는 경고 메시지와 함께 컴파일이 되지만, 해당 함수를 사용하지만 않는다면 완전한 static build가 가능해집니다.
>
> ```shell
> $ ldd out/bin/my_project 
>      동적 실행 파일이 아닙니다
> ```

### DoxyGen Importing

**Commit Version**: [ADD] Add Example for Doxygen `09dd8a88`

아래와 같이 CMakeList.txt에 Doxygen 라이브러리를 찾아 준 다음에, Doxygen을 위한 변수들을 설정해준 뒤 build를 하면 코드에 대한 문서가 생성됩니다.

```cmake
find_package(Doxygen REQUIRED)
# Configure the Doxygen input and output directories
set(
        DOXYGEN_INPUT_DIRS
        "${CMAKE_SOURCE_DIR}/src"
)
set(DOXYGEN_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/docs")

# Set Doxygen configuration options
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN NO)
set(DOXYGEN_OUTPUT_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

# Add a target for generating Doxygen documentation
doxygen_add_docs(
        doxygen_docs
        ${DOXYGEN_INPUT_DIR}
        COMMENT "Generate Doxygen documentation"
)
```
