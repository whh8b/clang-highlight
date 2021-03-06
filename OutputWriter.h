//===--- OutputWriter.h - clang-highlight -----------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_CLANG_HIGHLIGHT_OUTPUT_WRITER_H
#define LLVM_CLANG_TOOLS_CLANG_HIGHLIGHT_OUTPUT_WRITER_H

#include "llvm/ADT/StringRef.h"
#include <memory>

namespace clang {
namespace highlight {

enum class OutputFormat {
  StdoutColored,
  HTML,
  SemanticHTML,
  LaTeX,
  // TODO: XML, LaTeX, SemanticLaTeX, ...
};

enum class TokenClass {
  NONE,
  Type,
  Variable,
  Function,
  Namespace,
  Keyword,
  Comment,
  Preprocessor,
  String,
  Char,
  Numeric,
  Other,
  Whitespace,
};

class OutputWriter {
public:
  virtual void writeToken(llvm::StringRef Text, TokenClass Class) = 0;
  virtual ~OutputWriter();
};

// \brief Creates a output writer that writes in the specified Format to stdout
std::unique_ptr<OutputWriter> makeOutputWriter(OutputFormat Format,
                                               llvm::raw_ostream &OS);

} // end namespace highlight
} // end namespace clang

#endif // LLVM_CLANG_TOOLS_CLANG_HIGHLIGHT_OUTPUT_WRITER_H
