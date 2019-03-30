import hashlib as hlib
import datetime as dt

# Block class
class Block:
    def __init__(self, index, timestamp, data, prev_hash):
        self.index = index
        self.timestamp = timestamp
        self.data = data
        self.prev_hash = prev_hash
        self.hash = self.generate_block_hash()

    # Function to generate hash for the current block.
    def generate_block_hash(self):
        text = str(self.index) + str(self.timestamp) + str(self.data) + str(self.prev_hash)
        sha = hlib.sha256(text.encode('utf-8'))
        return sha.hexdigest()

# Function to generate genesis block which has
# index = 0, time stamp = current time,
# data = "Genensis Block", prev_hash = "0"
def create_genesis_block():
    return Block(0, dt.datetime.now(), "Genesis Block", 0)

# Function to add new block in the chain
# prev_block : previous block in the chain.
def add_block(prev_block):
    index = prev_block.index + 1
    timestamp = dt.datetime.now()
    data = "Person %d paid Rs.100 to Person %d"%(index, index + 1)
    #data = "Persona A paid Rs.100 to Person B"
    prev_hash = prev_block.prev_hash
    return Block(index, timestamp, data, prev_hash)

if __name__ == "__main__":
    # Create block chain list with first block
    blocks = [create_genesis_block()]

    # Create and add 4 more blocks to chain.
    for i in range(0,4):
        new_block = add_block(blocks[i])
        blocks.append(new_block)

    # Print all block's data and hash
    for b in blocks:
        print(b.data)
        print(b.hash)

