

class Slab:
    def __init__(self, object_size, objs_per_slab = 10):
        self.slabs = []
        self.object_size = object_size
        self.objs_per_slab = objs_per_slab

    def _internal_alloc(self): 
        slab = {
            "memory": bytearray(self.object_size * self.objs_per_slab),
            "available": set(range(self.objs_per_slab))
        }
        self.slabs.append(slab)

    def alloc(self):
        for slab in self.slabs:
            if slab["available"]: # if len(slab["available"]) != 0
                slab["available"].pop()
                return (slab, index)
        self._internal_alloc()
        return

    def free(self, slab, index):
        slab["available"].add(index)


struct_size = 200  # bytes
allocator = Slab(struct_size)