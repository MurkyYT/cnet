# cnet::Instance

**Instance** is not really used, it is only used in the windows operating system to initialize WSA and cleanup after it.
Ideally should be called always just in case.

### Methods

| Name  |  Description | Return type |
|-------|--------------|-------------|
|Initialize|Initializes needed dll's/so's|void|
|Uninitialize|Cleans everything up|void|