#include <google/protobuf/descriptor.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/tokenizer.h>
 
#include <google/protobuf/compiler/parser.h>
 
char text[] = "syntax = \"proto2\";\n"
  "message APIPort3 {"
  "required uint32 AppLedStateOn = 1;"
  "required uint32 PotiPercentage = 2;"
  "required uint32 VDD = 3;"
  "}";
std::string message_type("APIPort3");
 
int main() {
  using namespace google::protobuf;
  using namespace google::protobuf::io;
  using namespace google::protobuf::compiler;
 
  ArrayInputStream raw_input(text, strlen(text));
  Tokenizer input(&raw_input, NULL);
 

  FileDescriptorProto file_desc_proto;
  Parser parser;
  if (!parser.Parse(&input, &file_desc_proto)) {
    std::cerr << "Failed to parse .proto definition:" << text;
    return -1;
  }
 
  if (!file_desc_proto.has_name()) {
    file_desc_proto.set_name(message_type);
  }
 

  google::protobuf::DescriptorPool pool;
  const google::protobuf::FileDescriptor* file_desc =
    pool.BuildFile(file_desc_proto);
  if (file_desc == NULL) {
    std::cerr << "Cannot get file descriptor from file descriptor proto"
      << file_desc_proto.DebugString();
    return -1;
  }
 
  const google::protobuf::Descriptor* message_desc =
    file_desc->FindMessageTypeByName(message_type);
  if (message_desc == NULL) {
    std::cerr << "Cannot get message descriptor of message: " << message_type
      << ", DebugString(): " << file_desc->DebugString();
    return -2;
  }
 
  for (uint8_t i = 1; i <= message_desc->field_count(); i++) {
     const FieldDescriptor* field = message_desc->FindFieldByNumber(i);
     if (field)
       std::cout << field->name() << ": " << field->type_name() << " ("
         << field->label() << ")" << std::endl;
     else
       std::cerr << "Error fieldDescriptor object is NULL, field_count() = "
         << message_desc->field_count() << std::endl;
  }
 
  google::protobuf::DynamicMessageFactory factory;
  const google::protobuf::Message* prototype_msg =
    factory.GetPrototype(message_desc); // prototype_msg is immutable
  if (prototype_msg == NULL) {
    std::cerr << "Cannot create prototype message from message descriptor";
    return -3;
  }
 
  google::protobuf::Message* mutable_msg = prototype_msg->New();
  if (mutable_msg == NULL) {
    std::cerr << "Failed in prototype_msg->New(); to create mutable message";
    return -4;
  }
 
  uint8_t buffer[] = {0x08, 0x00, 0x10, 0x64, 0x18, 0xF5, 0x2D};
  if (!mutable_msg->ParseFromArray(buffer, 7)) {
    std::cerr << "Failed to parse value in buffer";
  }
 
  const Reflection* reflection = mutable_msg->GetReflection();
  std::vector<const FieldDescriptor*> fields;
  reflection->ListFields(*mutable_msg, &fields);
  for (auto field_it = fields.begin(); field_it != fields.end(); field_it++) {
    const FieldDescriptor* field = *field_it;
     if (field) {

       uint32 value = reflection->GetUInt32(*mutable_msg, field);
       std::cout << field->name() << " -> " << value << std::endl;
     } else
       std::cerr << "Error fieldDescriptor object is NULL" << std::endl;
  }
 
  return 0;
}
