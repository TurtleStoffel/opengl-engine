# Naming Conventions

# Namespaces
- Everything in the Engine should be part of the `Engine` namespace.
- Nested namespaces must follow the folder structure, but it is not required that every subfolder contains a new namespace. (it is often useful that the namespace and folder name are plural to avoid naming collisions, such as `Components` namespace and the `Component` class)

# Includes
- Includes in the engine should always start from the root folder