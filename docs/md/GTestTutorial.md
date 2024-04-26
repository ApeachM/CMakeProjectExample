# GTest & CTest Tutorial

## GTest

### Introduction

GTest, 즉 Google Test는 C++ 프로그래밍 언어용으로 개발된 유닛 테스팅(unit testing) 프레임워크입니다. 이 프레임워크는 프로그래머가 C++ 응용 프로그램이나 라이브러리에 대한 유닛 테스트를 작성하고 실행할 수 있게 해줍니다.

GTest는 xUnit 아키텍처를 따르는데, 이는 다양한 프로그래밍 언어에 적용되는 일반적인 유닛 테스팅 패턴을 기반으로 합니다. 테스트 케이스를 정의하기 위해 매크로를 사용하고, 테스트들을 자동으로 수집하고 실행하는 메커니즘을 제공합니다.

이 프레임워크의 주요 특징은 다음과 같습니다:
- **테스트 케이스와 테스트 스위트 관리**: 간편한 API를 통해 테스트 케이스와 테스트 스위트를 정의하고 관리할 수 있습니다.
- **다양한 어설션 지원**: `ASSERT_*` 및 `EXPECT_*` 등의 매크로를 사용하여 다양한 조건을 테스트 할 수 있습니다. `ASSERT_*` 매크로는 실패 시 테스트를 즉시 중단시키는 반면, `EXPECT_*` 매크로는 실패해도 테스트를 계속 진행시킵니다.
- **테스트 필터링**: 실행할 특정 테스트를 지정하거나 제외할 수 있어 대규모 테스트 스위트를 관리할 때 유용합니다.
- **결과 출력**: 테스트 결과를 다양한 포맷(XML 등)으로 출력할 수 있어, CI/CD 파이프라인과 같은 자동화된 시스템과 통합하기 쉽습니다.

GTest는 개발자들이 자신의 코드가 예상대로 작동하는지 검증하고, 리팩토링이나 기타 변경 사항 후에도 기능이 올바르게 유지되는지 확인하는 데 필수적인 도구입니다.



**Commit Version**: `7f4ce2ee`

### 파일 구조

```
.
├── CMakeLists.txt
├── README.md
├── docs
│   ├── md
│   │   ├── CMakeTutorial.md
│   │   └── GTestTutorial.md
│   └── style
│       └── googleTestStyleSheet.xsl
├── scripts
│   ├── runCMake.sh
│   ├── runCTest.sh
│   ├── runGTest.sh
│   └── runGTestWithOutput.sh
├── src
│   ├── CMakeLists.txt
│   ├── main.cpp
│   ├── myClass.cpp
│   ├── myClass.h
│   ├── myFunction.cpp
│   └── myFunction.h
└── test
    ├── CMakeLists.txt
    ├── test_class_main.cpp
    └── test_function_main.cpp
```

### 코드 작성

다음과 같이 `test` 디렉토리에 CMake 파일을 만들고 최상위 CMake는 다음과 같이 해줍니다.

```cmake
cmake_minimum_required(VERSION 3.20)
project(CppProjectTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/bin")

find_package(GTest REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
```

`test/CMakeList.txt` 는 아래와 같이 해줍니다.

```cmake
# Add the executable target for the test
add_executable(my_function_tests test_function_main.cpp)
# Link the executable target for the test with gtest, gtest_main, and the library which will be tested.
target_link_libraries(
        my_function_tests
        PRIVATE
        my_library
        GTest::gtest
        GTest::gtest_main
)
```

`test/test_function_main.cpp` 파일은 아래와 같이 해줍니다.

```cpp
#include <gtest/gtest.h>
#include "myFunction.h"

// AddTest 그룹
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(1, 2), 3);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add(-1, -1), -2);
}

TEST(AddTest, NegativeNumbers1) {
    EXPECT_EQ(add(-1, -1), -2);
}

TEST(AddTest, PositiveAndNegativeNumber) {
    EXPECT_EQ(add(-1, 1), 0);
}

// SubtractTest 그룹
TEST(SubtractTest, PositiveNumbers) {
    EXPECT_EQ(subtract(5, 3), 2);
}

TEST(SubtractTest, NegativeNumbers) {
    EXPECT_EQ(subtract(-1, -1), 0);
}

TEST(SubtractTest, UsingZero) {
    EXPECT_EQ(subtract(0, 0), 0);
}

// 메인 함수
int main(int argc, char **argv) {
    // Init the google test
    ::testing::InitGoogleTest(&argc, argv);

    // Do all tests and return the result
    return RUN_ALL_TESTS();
}
```

### Suite & Test 확인

 `out/bin` 안에 `my_function_tests` 바이너리가 만들어집니다. 이를 이용하여 바로 실행할 수 있지만, 그 전에 만들어진 Suite과 Test에 무엇이 있는지 확인해봅시다.

```shell
out/bin/my_function_tests --gtest_list_tests
```

```log
AddTest.
  PositiveNumbers
  NegativeNumbers
  NegativeNumbers1
  PositiveAndNegativeNumber
SubtractTest.
  PositiveNumbers
  NegativeNumbers
  UsingZero
```

다음과 같이 2개의 Suite 안에 7개의 Testcase가 있음을 확인할 수 있습니다.

### 실행

#### 일반 실행

생성된 바이너리를 실행하면 자동으로 7개의 테스트케이스를 실행하여 다음과 같이 출력됩니다.

```shell
out/bin/my_function_tests
```

```log
[==========] Running 7 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from AddTest
[ RUN      ] AddTest.PositiveNumbers
[       OK ] AddTest.PositiveNumbers (0 ms)
[ RUN      ] AddTest.NegativeNumbers
[       OK ] AddTest.NegativeNumbers (0 ms)
[ RUN      ] AddTest.NegativeNumbers1
[       OK ] AddTest.NegativeNumbers1 (0 ms)
[ RUN      ] AddTest.PositiveAndNegativeNumber
[       OK ] AddTest.PositiveAndNegativeNumber (0 ms)
[----------] 4 tests from AddTest (0 ms total)

[----------] 3 tests from SubtractTest
[ RUN      ] SubtractTest.PositiveNumbers
[       OK ] SubtractTest.PositiveNumbers (0 ms)
[ RUN      ] SubtractTest.NegativeNumbers
[       OK ] SubtractTest.NegativeNumbers (0 ms)
[ RUN      ] SubtractTest.UsingZero
[       OK ] SubtractTest.UsingZero (0 ms)
[----------] 3 tests from SubtractTest (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 7 tests.
```

### 필터와 함께 실행

명령줄에서 Google Test 실행 파일에 필터를 적용하여 특정 테스트 케이스만 실행하는 방법은 매우 간단합니다. 이를 위해 `--gtest_filter` 옵션을 사용할 수 있습니다. 여기서는 제공된 테스트 스위트와 케이스를 기반으로 몇 가지 예를 들어 보겠습니다.

#### 기본 사용법
```bash
./my_tests --gtest_filter=테스트스위트.테스트케이스
```

#### 구체적인 예시들

1. **AddTest 스위트의 모든 테스트를 실행**:
   
   ```bash
   ./my_tests --gtest_filter=AddTest.*
   ```
   이 필터는 `AddTest` 스위트에 속한 모든 테스트 (`PositiveNumbers`, `NegativeNumbers`, `NegativeNumbers1`, `PositiveAndNegativeNumber`)를 실행합니다.
   
2. **SubtractTest 스위트에서 NegativeNumbers 테스트만 실행**:
   ```bash
   ./my_tests --gtest_filter=SubtractTest.NegativeNumbers
   ```
   이 명령은 `SubtractTest` 스위트 중 `NegativeNumbers` 테스트만 실행합니다.

3. **모든 스위트의 NegativeNumbers 테스트만 실행**:
   ```bash
   ./my_tests --gtest_filter=*.NegativeNumbers
   ```
   `AddTest`와 `SubtractTest` 스위트 모두에서 `NegativeNumbers`라는 이름의 테스트를 실행합니다.

4. **AddTest 스위트에서 NegativeNumbers를 제외한 모든 테스트 실행**:
   ```bash
   ./my_tests --gtest_filter=AddTest.*-AddTest.NegativeNumbers
   ```
   이 필터는 `AddTest` 스위트 내의 `NegativeNumbers` 테스트를 제외한 모든 테스트를 실행합니다.

5. **여러 특정 테스트 실행**:
   ```bash
   ./my_tests --gtest_filter=AddTest.PositiveNumbers:SubtractTest.UsingZero
   ```
   이 필터를 사용하면 `AddTest` 스위트의 `PositiveNumbers` 테스트와 `SubtractTest` 스위트의 `UsingZero` 테스트만을 실행합니다. 각 테스트는 콜론(`:`)으로 구분됩니다.

이러한 필터링 옵션을 사용하여, 필요한 테스트만 선택적으로 실행할 수 있어 테스트 과정을 보다 효율적으로 관리할 수 있습니다.





### Fixture-Based Test

**Commit Version**: `50cabaf3`

테스트 픽스처(test fixture)를 사용하는 것을 "픽스처 기반 테스트(fixture-based testing)"라고 합니다. 이 방식은 테스트 실행 전에 필요한 환경이나 상태를 설정하고, 테스트 후에 이를 정리하는 일련의 작업을 포함합니다. Google Test에서는 `TEST_F()` 매크로를 사용하여 픽스처 기반 테스트를 정의할 수 있습니다.

픽스처를 사용하는 목적은 여러 테스트에서 공통적으로 필요한 초기화와 정리 작업을 재사용함으로써, 테스트 코드의 중복을 줄이고, 코드의 유지 관리를 용이하게 하는 데 있습니다. 예를 들어, 데이터베이스 연결, 파일 시스템의 특정 상태 설정, 복잡한 객체의 초기화 등을 픽스처에서 처리할 수 있습니다.

픽스처 기반 테스트는 다음과 같은 구조로 작성됩니다:

1. **픽스처 클래스 정의**: 사용자는 `::testing::Test` 클래스를 상속받는 클래스를 정의합니다. 이 클래스 내에서 필요한 데이터 멤버와 메소드(`SetUp()` 및 `TearDown()`)를 정의하여 테스트 전의 준비 작업과 테스트 후의 정리 작업을 구현할 수 있습니다.

2. **테스트 케이스 작성**: 정의된 픽스처 클래스를 사용하여 `TEST_F()` 매크로를 통해 테스트 케이스를 작성합니다. 이 매크로는 픽스처 클래스 이름과 테스트 케이스 이름을 인자로 받습니다. 테스트 케이스 내에서는 픽스처 클래스의 데이터 멤버와 메소드에 접근할 수 있으며, 필요한 테스트 로직을 구현합니다.

픽스처 기반 테스트는 각 테스트가 독립적인 상태에서 실행될 수 있도록 보장하는 동시에, 공통의 설정 및 정리 코드를 중복 없이 관리할 수 있게 해 줍니다.

#### 파일 구조

```
src
	CMakeLists.txt
	myClass.cpp
	myClass.h
	...
test
	CMakeLists.txt
	test_class_main.cpp
	test_function_main.cpp
	...
```

위에 해당되는 파일을 더하기 및 수정해줍니다. 자세한 내용은 `50cabaf3` 커밋에서 보실 수 있습니다.

#### 코드 작성

`src/myClass.cpp`

```cpp
#include "myClass.h"

int Calculator::Add(int a, int b) {
  return a + b;
}

int Calculator::Subtract(int a, int b) {
  return a - b;
}

int Calculator::Multiply(int a, int b) {
  return a * b;
}
```

`src/myClass.h`

```cpp
#ifndef MYCLASS_H
#define MYCLASS_H

class Calculator {
 public:
  int Add(int a, int b);

  int Subtract(int a, int b);

  int Multiply(int a, int b);
};

#endif // MYCLASS_H
```

`test/test_class_main.cpp`

```cpp
#include <gtest/gtest.h>
#include "myClass.h"

// CalculatorTest 테스트 픽스처 클래스 정의
class CalculatorTest : public ::testing::Test {
 protected:
  Calculator calc;  // 각 테스트 케이스에서 사용할 Calculator 객체

  // 테스트 전에 실행되는 코드
  void SetUp() override {
    // 필요한 경우 초기화 코드 작성
  }

  // 테스트 후에 실행되는 코드
  void TearDown() override {
    // 필요한 경우 정리 코드 작성
  }
};

// Add 메서드 테스트
TEST_F(CalculatorTest, TestAdd) {
  EXPECT_EQ(calc.Add(1, 2), 3);
  EXPECT_EQ(calc.Add(-1, 1), 0);
  EXPECT_EQ(calc.Add(100, 200), 300);
}

// Subtract 메서드 테스트
TEST_F(CalculatorTest, TestSubtract) {
  EXPECT_EQ(calc.Subtract(5, 3), 2);
  EXPECT_EQ(calc.Subtract(10, 15), -5);
  EXPECT_EQ(calc.Subtract(0, 0), 0);
}

// Multiply 메서드 테스트
TEST_F(CalculatorTest, TestMultiply) {
  EXPECT_EQ(calc.Multiply(5, 2), 10);
  EXPECT_EQ(calc.Multiply(-1, 3), -3);
  EXPECT_EQ(calc.Multiply(0, 10), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

#### 코드 설명

위 코드처럼 클래스를 만들게 된다면, Suite 이름은 클래스 이름이 됩니다. Suite 항에 클래스가 들어가면 `TEST_F` 함수는 그 클래스의 하나의 메소드가 되며, 이를 이용하여 테스트케이스를 작성할 수 있습니다.

#### Suite & Testcase 확인

```shell
out/bin/my_class_tests --gtest_list_tests
```

```log
CalculatorTest.
  TestAdd
  TestSubtract
  TestMultiply
```

다음과 같이 Class name과 같은 Suite 안에 Testcase 3개가 있음을 확인할 수 있습니다.

### Publish The Report

**Commit Version**: `839bffc4`

```
out/bin/my_tests --gtest_output=xml:$output_xml
```

다음 명령어처럼 바이너리를 실행하면 test 결과에 대한 리포트가 xml 파일로 나옵니다. 이 xml 파일을 xsl 파일과 함께 html로 변환시켜주면  [다음과 같은 예시](../exmamples/gtestResultExample.html)  가 나옵니다. 해당 실행은  [`scripts/runGTestWithOutput.sh`](../../scripts/runGTestWithOutput.sh) 에서 가능합니다.



## CTest

CTest는 CMake 기반의 Testing 도구이며, GTest 뿐만 아니라 Catch, Boost, shell testing 등 여러 테스팅과 통합이 가능합니다. 또한 **병렬로 시행**이 되며 CDash라는 서비스와 함께 통합이 되어 쉽게 Report Publish도 가능합니다. ([예시](https://i0.wp.com/embeddeduse.com/wp-content/uploads/2022/05/cdash-pipeline-2.png?ssl=1))

### GTest & CTest 통합 방법

**Commit Version**: `3f445e61`

`test/CMakeLists.txt`의 맨 밑에 다음과 같이 추가하였습니다.

```cmake
...
include(CTest)
# To use gtest_discover_test function
include(GoogleTest)
# find the test cases automatically and execute them
gtest_discover_tests(my_tests)
gtest_discover_tests(my_class_tests)
...
```

이렇게 된다면 `my_tests`와 `my_class_tests`안에 있는 각 Test case들이 CTest의 항목안에 들어가게 됩니다.

최상위 `CMakeLists.txt`에서는 마지막에 다음과 같이 줄을 추가합니다.

```cmake
...
enable_testing()
```

#### 실행 방법

그 다음에 `build` 폴더 안으로 들어가 다음과 같이 ctest를 실행해줍니다.

```shell
cd build
ctest # 또는
ctest -j # 또는
ctest --parallel # 또는
ctest --parallel 10 
```

그럼 아래와 같은 결과가 나오게 됩니다.

```
Test project /home/minjae-baum/CLionProjects/CMakeProjectExample/build
      Start  1: AddTest.PositiveNumbers
 1/10 Test  #1: AddTest.PositiveNumbers .............   Passed    0.00 sec
      Start  2: AddTest.NegativeNumbers
 2/10 Test  #2: AddTest.NegativeNumbers .............   Passed    0.00 sec
      Start  3: AddTest.NegativeNumbers1
 3/10 Test  #3: AddTest.NegativeNumbers1 ............   Passed    0.00 sec
      Start  4: AddTest.PositiveAndNegativeNumber
 4/10 Test  #4: AddTest.PositiveAndNegativeNumber ...   Passed    0.00 sec
      Start  5: SubtractTest.PositiveNumbers
 5/10 Test  #5: SubtractTest.PositiveNumbers ........   Passed    0.00 sec
      Start  6: SubtractTest.NegativeNumbers
 6/10 Test  #6: SubtractTest.NegativeNumbers ........   Passed    0.00 sec
      Start  7: SubtractTest.UsingZero
 7/10 Test  #7: SubtractTest.UsingZero ..............   Passed    0.00 sec
      Start  8: CalculatorTest.TestAdd
 8/10 Test  #8: CalculatorTest.TestAdd ..............   Passed    0.00 sec
      Start  9: CalculatorTest.TestSubtract
 9/10 Test  #9: CalculatorTest.TestSubtract .........   Passed    0.00 sec
      Start 10: CalculatorTest.TestMultiply
10/10 Test #10: CalculatorTest.TestMultiply .........   Passed    0.00 sec

100% tests passed, 0 tests failed out of 10

Total Test time (real) =   0.01 sec
```

해당 각 테스트는 모두 병렬로 실행됩니다.

### 일반 테스트와 통합 방법

Commit Version: `3f445e61`

CTest에는 GTest 이외의 테스트도 모두 통합이 됩니다. `test/CMakeLists.txt` 안에 다음과 같이 테스트를 추가할 수 있습니다.

```shell
...
include(CTest)
# To use gtest_discover_test function
include(GoogleTest)
# find the test cases automatically and execute them
gtest_discover_tests(my_tests)
gtest_discover_tests(my_class_tests)


add_test(NAME cTestCase1 COMMAND sh -c "sleep 1")
add_test(NAME cTestCase2 COMMAND sh -c "sleep 2")
```

이전과 다른 부분은 맨 밑 두 줄입니다. cTestCase1와 cTestCase2를 추가하였고, `build` 안에서 다음 명령어를 사용하면 다음과 같은 출력이 나옵니다.

```shell
ctest --parallel
```

```
Test project /home/minjae-baum/CLionProjects/CMakeProjectExample/build
      Start 12: cTestCase2
      Start 11: cTestCase1
      Start  3: AddTest.NegativeNumbers1
      Start  1: AddTest.PositiveNumbers
 1/12 Test  #3: AddTest.NegativeNumbers1 ............   Passed    0.00 sec
      Start  6: SubtractTest.NegativeNumbers
 2/12 Test  #1: AddTest.PositiveNumbers .............   Passed    0.00 sec
      Start  2: AddTest.NegativeNumbers
 3/12 Test  #6: SubtractTest.NegativeNumbers ........   Passed    0.00 sec
      Start  7: SubtractTest.UsingZero
 4/12 Test  #2: AddTest.NegativeNumbers .............   Passed    0.00 sec
      Start 10: CalculatorTest.TestMultiply
 5/12 Test  #7: SubtractTest.UsingZero ..............   Passed    0.00 sec
      Start  9: CalculatorTest.TestSubtract
 6/12 Test #10: CalculatorTest.TestMultiply .........   Passed    0.00 sec
      Start  5: SubtractTest.PositiveNumbers
 7/12 Test  #9: CalculatorTest.TestSubtract .........   Passed    0.00 sec
      Start  4: AddTest.PositiveAndNegativeNumber
 8/12 Test  #5: SubtractTest.PositiveNumbers ........   Passed    0.00 sec
      Start  8: CalculatorTest.TestAdd
 9/12 Test  #4: AddTest.PositiveAndNegativeNumber ...   Passed    0.00 sec
10/12 Test  #8: CalculatorTest.TestAdd ..............   Passed    0.00 sec
11/12 Test #11: cTestCase1 ..........................   Passed    1.00 sec
12/12 Test #12: cTestCase2 ..........................   Passed    2.00 sec

100% tests passed, 0 tests failed out of 12

Total Test time (real) =   2.00 sec
```

해당 테스트를 보았을 때, manual하게 만든 test와 GTest로 만든 test가 같이 실행되는 것을 알 수 있습니다.

### Export the Result

```bash
ctest --output-junit ctest-results.xml
```

위 명령어와 함께라면 xml 파일을 만들 수 있습니다. GTest와 같이 xsl을 작성하면 추후 html로 리포트가 가능합니다. 현재는 미작성이지만, 외부 툴을 이용한 예시는 [다음](../exmamples/ctestResultExample.html)과 같습니다.

