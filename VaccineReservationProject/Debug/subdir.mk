################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Citizen.cpp \
../Government.cpp \
../LinkedList.cpp \
../Node.cpp \
../Queue.cpp \
../main.cpp 

OBJS += \
./Citizen.o \
./Government.o \
./LinkedList.o \
./Node.o \
./Queue.o \
./main.o 

CPP_DEPS += \
./Citizen.d \
./Government.d \
./LinkedList.d \
./Node.d \
./Queue.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


