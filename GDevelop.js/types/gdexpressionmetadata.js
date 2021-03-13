// Automatically generated by GDevelop.js/scripts/generate-types.js
declare class gdExpressionMetadata {
  constructor(returnType: string, extensionNamespace: string, name: string, fullname: string, description: string, group: string, smallicon: string): void;
  getReturnType(): string;
  getFullName(): string;
  getDescription(): string;
  getGroup(): string;
  getSmallIconFilename(): string;
  isShown(): boolean;
  isPrivate(): boolean;
  getParameter(id: number): gdParameterMetadata;
  getParametersCount(): number;
  getParameters(): gdVectorParameterMetadata;
  setHidden(): gdExpressionMetadata;
  setPrivate(): gdExpressionMetadata;
  addParameter(type: string, description: string, optionalObjectType?: string, parameterIsOptional?: boolean): gdExpressionMetadata;
  addCodeOnlyParameter(type: string, supplementaryInformation: string): gdExpressionMetadata;
  setDefaultValue(defaultValue: string): gdExpressionMetadata;
  setParameterLongDescription(longDescription: string): gdExpressionMetadata;
  getCodeExtraInformation(): gdExpressionCodeGenerationInformation;
  delete(): void;
  ptr: number;
};