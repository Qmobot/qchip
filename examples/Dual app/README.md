# Dual-core

The ESP32 comes with 2 Xtensa 32-bit LX6 microprocessors: core 0 and core 1. So, it is dual core. When we run code on Arduino IDE, by default, it runs on core 1. In this post we’ll show you how to run code on the ESP32 second core by creating tasks. You can run pieces of code simultaneously on both cores, and make your ESP32 multitasking.

## Introduction

The ESP32 comes with 2 Xtensa 32-bit LX6 microprocessors, so it’s dual core:

1. Core 0
2. Core 1

![](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/10/esp32-block-diagram.png)

When we upload code to the ESP32 using the Arduino IDE, it just runs – we don’t have to worry which core executes the code.

There’s a function that you can use to identify in which core the code is running:
``xPortGetCoreID()``

If you use that function in an Arduino sketch, you’ll see that both the `setup()` and `loop()` are running on core 1. Test it yourself by uploading the following sketch to your ESP32.

```
void setup() {
  Serial.begin(115200);
  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
}

void loop() {
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());
}
```

## Create Tasks

The Arduino IDE supports FreeRTOS for the ESP32, which is a Real Time Operating system. This allows us to handle several tasks in parallel that run independently.

Tasks are pieces of code that execute something. For example, it can be blinking an LED, making a network request, measuring sensor readings, publishing sensor readings, etc…

To assign specific parts of code to a specific core, you need to create tasks. When creating a task you can chose in which core it will run, as well as its priority. Priority values start at 0, in which 0 is the lowest priority. The processor will run the tasks with higher priority first.

To create tasks you need to follow the next steps:

1. Create a task handle. An example for Task1:

``TaskHandle_t Task1;``

2. In the `setup()` create a a task assigned to a specific core using the `xTaskCreatePinnedToCore` function. That function takes several arguments, including the priority and the core where the task should run (the last parameter).

```
xTaskCreatePinnedToCore(
      Task1code, /* Function to implement the task */
      "Task1", /* Name of the task */
      10000,  /* Stack size in words */
      NULL,  /* Task input parameter */
      0,  /* Priority of the task */
      &Task1,  /* Task handle. */
      0); /* Core where the task should run */
```

3. After creating the task, you should create a function that contains the code for the created task. In this example you need to create the `Task1code()` function. Here’s how the task function looks like:

```
Void Task1code( void * parameter) {
  for(;;) {
    Code for task 1 - infinite loop
    (...)
  }
}
```

The `for(;;)` creates an infinite loop. So, this function runs similarly to the `loop()` function. You can use it as a second loop in your code, for example.

If during your code execution you want to delete the created task, you can use the `vTaskDelete()` function, that accepts the task handle (Task1) as argument:

``vTaskDelete(Task1);``


